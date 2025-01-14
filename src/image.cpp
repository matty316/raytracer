#include "image.h"

#include <iostream>
#include <fstream>

uint32_t get_color(const uint8_t r, const uint8_t g, const uint8_t b, uint8_t a) {
	return (a << 24) + (b << 16) + (g << 8) + r;
}

void get_components(uint32_t& color, uint8_t& r, uint8_t& g, uint8_t& b, uint8_t& a) {
	r = (color >> 0) & 255;
	g = (color >> 8) & 255;
	b = (color >> 16) & 255;
	a = (color >> 24) & 255;
}

bool write_image(const size_t w, const size_t h, const std::vector<uint32_t> colors) {
	std::ofstream file("out.ppm", std::ios::binary);
	if (!file.is_open()) {
		std::cerr << "ERROR: CANNOT OPEN FILE" << '\n';
		return false;
	}

	file << "P6\n" << w << " " << h << '\n' << "255\n";

	for (size_t j = 0; j < h; j++) {
		std::clog << "\rLines remaining: " << h - j << ' ' << std::flush;
		for (size_t i = 0; i < w; i++) {
			uint32_t color = colors[i + j * w];
			uint8_t r, g, b, a;
			get_components(color, r, g, b, a);

			file << static_cast<char>(r) << static_cast<char>(g) << static_cast<char>(b);
		}
	}

	file.close();
	std::clog << "\rPPM file written successfully" << '\n';
	return true;
}