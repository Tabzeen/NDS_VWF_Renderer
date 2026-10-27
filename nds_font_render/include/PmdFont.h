
#pragma once

#include <optional>
#include "CharData.h"
#include "PmdFont_bin.h"

std::optional<uint16_t> map_fn(uint16_t in) {

    if(in >= 0x21 && in < 0x21 + 96)
        return in - 0x21;

    return std::nullopt;
}

namespace Fonts::PmdFont {

    constexpr CharData Data = {
        .version        = 512,
        .font_dim       = 16,
        .char_cnt       = 96,
        .char_size_u8   = 32,
        .strides        = PmdFont_bin + 8,
        .pixels         = PmdFont_bin + 104,
        .map_fn         = &map_fn
    };

}
