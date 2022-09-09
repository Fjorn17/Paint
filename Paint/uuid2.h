#pragma once

#include <random>
#include <sstream>

namespace uuid {
    static std::random_device              rd;
    static std::mt19937                    gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);

    std::string generate_uuid_v4() {
        std::stringstream ss;
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 4; i++) {
            ss << dis(gen);
        }
        ss << "-4";
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 12; i++) {
            ss << dis(gen);
        };
        return ss.str();
    }
}

//Forma 2:

class random_char_source
{
    const std::string chars;
    std::mt19937 generator;
    std::uniform_int_distribution<std::size_t> distribution;

public:
    using iterator_category = std::input_iterator_tag;
    using value_type = char;
    using difference_type = int;
    using pointer = const char*;
    using reference = const char&;

    explicit random_char_source(std::string chars, std::random_device::result_type seed = std::random_device{}())
        : chars{ std::move(chars) },
        generator{ seed },
        distribution{ 0, this->chars.size() - 1 }
    {}

    char operator*() { return chars[distribution(generator)]; }
    random_char_source& operator++() { return *this; }
};

static std::string generate_random_id(std::size_t len)
{
    auto hex_chars = random_char_source{ "0123456789abcdef" };

    std::string uuid;
    uuid.reserve(len);
    std::copy_n(hex_chars, len, std::back_inserter(uuid));
    return uuid;
}

