#ifndef ASSETMAN
#define ASSETMAN


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <map>

class AssetMan
{
public:
	AssetMan();
	~AssetMan();

	//Textures
	void SetTexture(std::string id, std::string path);
	sf::Texture &GetTexture(std::string id);

	//Fonts
	void SetFont(std::string id, std::string path);
	sf::Font &GetFont(std::string id);

	//Sounds
	void SetBuffer(std::string id, std::string path);
	sf::SoundBuffer &GetBuffer(std::string id);

private:
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, sf::Font> fonts;
	std::map<std::string, sf::SoundBuffer> sound_buffers;
	
};
#endif // ! ASSETMAN

