/*
 * Copyright (c) 2022, Štěpán Balážik <stepan@balazik.cz>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include "IDNA.h"
#include "AK/Utf8View.h"
#include <AK/CharacterTypes.h>
#include <AK/StringBuilder.h>

#define PUNYCODE_SEPARATOR '-'

namespace DNS {

constexpr size_t label_length_limit = 63;

// RFC 3492 3.1 Basic code point segregation
static String basic_codepoint_separation(Utf8View view) {
    size_t index = 0;
    size_t byte_length = 0;
    auto basic_codepoints = StringBuilder(label_length_limit);
    for (auto it = view.begin(); it != view.end(); ++it, index += byte_length) {
        u32 code_point = *it;
        byte_length = it.underlying_code_point_length_in_bytes();
        if (is_ascii(code_point)) {
            basic_codepoints.append(code_point);
        }
    }
    if (!basic_codepoints.is_empty()) {
        basic_codepoints.append(PUNYCODE_SEPARATOR);
    }
    return basic_codepoints.to_string();
}

// RFC 3492 3.1. Insertion unsort coding


String to_punycode(StringView string)
{
    auto out = StringBuilder(label_length_limit);
    out.append(basic_codepoint_separation(Utf8View{string}))


}

}
