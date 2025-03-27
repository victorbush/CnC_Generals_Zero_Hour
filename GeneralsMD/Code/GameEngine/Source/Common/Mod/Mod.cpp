//
// Created by victo on 3/24/2025.
//

#include "Common/Mod.h"

#include "toml.h"

ModManager::ModManager(std::experimental::filesystem::path mod_dir_base_path)
    : mod_dir_base_path(mod_dir_base_path)
{
}

Mod ModManager::load_mod(const std::string& mod_id)
{
    std::experimental::filesystem::path target_mod_dir = mod_dir_base_path / mod_id;
    std::experimental::filesystem::path target_mod_toml = target_mod_dir / "mod.toml";

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

    // TODO : Circular dependencies ?

    if (mod_config.contains("depends"))
    {
        auto d = mod_config["depends"].as_array();
        for (const auto& a : d)
        {
            Mod dependency = load_mod(a.as_string());
            mod.dependencies.push_back(dependency);
        }
    }



    return mod;
}
