#include "AssetMan.h"

AssetMan::AssetMan()
{
}

AssetMan::~AssetMan()
{
}

void AssetMan::SetTexture(std::string ID, std::string path)
{
	sf::Texture texture;

	if (texture.loadFromFile(path))
	{
		this->textures[ID] = texture;
	}
}

sf::Texture &AssetMan::GetTexture(std::string id)
{
	return this->textures.at(id);
}

void AssetMan::SetFont(std::string ID, std::string path)
{
	sf::Font font;

	if (font.loadFromFile(path))
	{
		this->fonts[ID] = font;
	}
}

sf::Font &AssetMan::GetFont(std::string id)
{
	return this->fonts.at(id);
}

void AssetMan::SetBuffer(std::string ID, std::string path)
{
	sf::SoundBuffer buffer;

	if (buffer.loadFromFile(path))
	{
		this->sound_buffers[ID] = buffer;
	}
}

sf::SoundBuffer &AssetMan::GetBuffer(std::string ID)
{
	return this->sound_buffers.at(ID);
}
