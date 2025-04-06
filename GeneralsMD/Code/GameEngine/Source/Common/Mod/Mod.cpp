//
// Created by victo on 3/24/2025.
//

#include "Common/Mod.h"

#include "toml.h"

namespace fs = std::experimental::filesystem;

ModManager::ModManager(fs::path mod_dir_base_path)
    : mod_dir_base_path(mod_dir_base_path)
{
}

Mod ModManager::load_mod(const std::string& mod_id)
{
    fs::path target_mod_dir = fs::absolute(mod_dir_base_path / mod_id);
    fs::path target_mod_toml = target_mod_dir / "mod.toml";

    if (!exists(target_mod_toml))
    {
        RELEASE_CRASH("mod.toml not found");
    }

    const auto t = toml::try_parse(target_mod_toml.string());
    if(t.is_err())
    {
        RELEASE_CRASH("Failed to parse mod config file");
    }

    auto mod_config = t.unwrap();

    Mod mod;
    mod.id = mod_id;

    if (!mod_config.contains("title"))
    {
        RELEASE_CRASH("Mod has no title.");
    }

    mod.title = mod_config["title"].as_string();
    mod.directory = target_mod_dir;
    mod.searchDirectories.push_back(target_mod_dir);

    if (mod_config.contains("bigDirs"))
    {
        auto d = mod_config["bigDirs"].as_array();
        for (const auto& a : d)
        {
            mod.bigDirectories.push_back(target_mod_dir / a.as_string());
        }
    }
    else
    {
        // Default search path is the mod directory root
        mod.bigDirectories.push_back(target_mod_dir);
    }

    if (mod_config.contains("depends"))
    {
        auto depends = mod_config["depends"].as_array();

        for (const auto& d : depends)
        {
            // TODO: Prevent circular dependencies.
            auto dependency = load_mod(d.as_string());

            for (const auto& dir : dependency.bigDirectories)
                mod.bigDirectories.push_back(dir);

            for (const auto& dir : dependency.searchDirectories)
                mod.searchDirectories.push_back(dir);
        }
    }

    return mod;
}
