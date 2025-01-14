#include "common.h"

int main() {
	const size_t w = 400;
	const size_t h = 400;

	std::vector<uint32_t> colors;
	for (size_t i = 0; i < w * h; i++) {
		colors.push_back(0xff0000ff);
	}
	if (!write_image(w, h, colors))
		return 1;
}
