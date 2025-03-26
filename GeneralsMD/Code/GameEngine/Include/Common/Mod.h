//
// Created by victo on 3/25/2025.
//

#pragma once

#include <string>
#include <vector>
#include <Common/FileSystem.h>
#include <experimental/filesystem>

struct Mod
{
    std::string id;
    std::string title;
    std::experimental::filesystem::path directory;
    std::vector<Mod> dependencies;
};

class ModManager
{
public:
    ModManager(std::experimental::filesystem::path mod_dir_base_path);
    Mod load_mod(const std::string& mod_id);

private:
    Mod current_mod;
    std::experimental::filesystem::path mod_dir_base_path;
};
