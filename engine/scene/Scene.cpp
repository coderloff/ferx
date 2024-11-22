#include "Scene.h"

void Scene::AddCube(const std::shared_ptr<Cube>& cube)
{
    cubes.push_back(cube);
}

std::shared_ptr<Cube> Scene::GetCubeByName(const std::string& name)
{
    for (const auto& cube : cubes)
    {
        if(cube->name == name)
        {
            return cube;
        }
    }
    return nullptr;
}

const std::vector<std::shared_ptr<Cube>>& Scene::GetCubes() const
{
    return cubes;
}


