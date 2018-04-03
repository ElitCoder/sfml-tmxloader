#ifndef TILE_INFO_H
#define TILE_INFO_H

#include <chrono>

namespace tmx {
	struct TileInfo //holds texture coords and tileset id of a tile
	{
		std::array<sf::Vector2f, 4> Coords;
		sf::Vector2f Size;
		sf::Uint16 TileSetId;
		TileInfo();
		TileInfo(const sf::IntRect& rect, const sf::Vector2f& size, sf::Uint16 tilesetId);
		
		std::vector<int> animation_tile_ids_;
		std::vector<int> animation_durations_;
		int animation_tile_id_;
		std::chrono::time_point<std::chrono::system_clock> next_animation_;
		int current_tile_;
		
		void setAnimationInformation(const std::vector<int>& tile_ids, const std::vector<int>& durations, int tile_id);
		bool animationElapsed();
		void animationStartTimer();
	};
}

#endif