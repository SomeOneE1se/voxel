/** ############################################################################
 *  \file   manager.cpp
 *  \author p@nsk
 *  \date   25.06.2026
 *  \brief
 * _____________________________________________________________________________
 */
#include "manager.h"
#include <graphics/shader.h>
#include <graphics/texture.h>

#include <sstream>
#include <fstream>
#include <iostream>

/**
 * @brief Manager::Manager
 * @param path
 ******************************************************************************/
Manager::Manager(
    const std::string& path
)
{
    size_t found = path.find_last_of("/\\");
    resPath = path.substr(0, found);
    dbgprint1("  Manager::resPath: %s\n", resPath.c_str());
}

/**
 * @brief Manager::getFileContent
 * @param path
 * @return
 ******************************************************************************/
std::string Manager::getFileContent(
	std::string path
	) const
{
    std::fstream file;
    file.open(resPath + "/" + path.c_str(), std::ios::in | std::ios::binary);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << path << std::endl;
        return std::string{};
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

/**
 * @brief Manager::loadShader
 * @param shaderName
 * @param vertex
 * @param fragment
 * @return
 ******************************************************************************/
std::shared_ptr<Render::Shader> Manager::loadShader (
    const std::string& shaderName,
    const std::string& vertex,
    const std::string& fragment
)
{
    std::string vertexString = getFileString(vertex);
    if (vertexString.empty())
    {
        std::cerr << "No vertex shader!" << std::endl;
        return nullptr;
    }

    std::string fragmentString = getFileString(fragment);
    if (fragmentString.empty())
    {
        std::cerr << "No fragment shader!" << std::endl;
        return nullptr;
    }
    std::shared_ptr<Render::Shader>& newShader = MShader.emplace(
        shaderName, std::make_shared<Render::Shader>(vertexString, fragmentString)).first->second;
    if (newShader->isCompiled())
    {
        return newShader;
    }
    else
    {
        std::cerr << "Cant load shader: \n"
                  << "Vertex: " << vertex << "\n"
                  << "Fragment: " << fragment << "\n";
        return nullptr;
    }
}

/**
 * @brief Manager::getShader
 * @param shaderName
 * @return
 ******************************************************************************/
std::shared_ptr<Render::Shader> Manager::getShader(
    const std::string shaderName
) const
{
    shaderMap::const_iterator it = MShader.find(shaderName);
    if (it != MShader.end())
        return it->second;
    else
        std::cerr << "Cant find the shader: " << shaderName << std::endl;
    return nullptr;
}

/**
 * @brief Manager::loadTexture
 * @param textureName
 * @param texture
 * @return
 ******************************************************************************/
std::shared_ptr<Render::Texture> Manager::loadTexture (
    const std::string& textureName,
    const std::string& texture
)
{
    std::shared_ptr<Render::Texture>& newTexture = MTexture.emplace(
        textureName, std::make_shared<Render::Texture>(texture)).first->second;
    if (newTexture->isLoaded())
    {
        return newTexture;
    }
    else
    {
        std::cerr << "Cant load Texture: " << texture << std::endl;
        return nullptr;
    }
}

/**
 * @brief Manager::getTexture
 * @param textureName
 * @return
 ******************************************************************************/
std::shared_ptr<Render::Texture> Manager::getTexture(
    const std::string textureName
) const
{
    textureMap::const_iterator it = MTexture.find(textureName);
    if (it != MTexture.end())
        return it->second;
    else
        std::cerr << "Cant find the texture: " << textureName << std::endl;
    return nullptr;
}
