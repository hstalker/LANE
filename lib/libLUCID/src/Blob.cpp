///////////////////////////////////////////////////////////////////////////////
/// \file Blob.cpp
/// \author Hector Stalker <hstalker0@gmail.com>
/// \version 0.1
///
/// \brief Blob storage class
///
/// \copyright Copyright (c) 2014, Hector Stalker. All rights reserved.
/// This file is under the Simplified (2-clause) BSD license
/// For conditions of distribution and use, see:
/// http://opensource.org/licenses/BSD-2-Clause
/// or read the 'LICENSE.md' file distributed with this code

#include <ostream>
#include <vector>
#include <cstdint>
#include "Pixel.hpp"
#include "Blob.hpp"

namespace lucid {

Blob::Blob() = default;

Blob::~Blob() noexcept = default;

Blob::Blob(const Blob& other) = default;

Blob::Blob(Blob&& other) = default;

Blob& Blob::operator=(const Blob& other) = default;

Blob& Blob::operator=(Blob&& other) = default;

bool Blob::operator==(const Blob& other) const noexcept {
    if (this != &other) {
        if(pixelKeys_.size() == other.pixelKeys_.size()) {
            return (
                pixelKeys_ == other.pixelKeys_
            );
        }

        return false;
    }

    return true;
}

bool Blob::operator!=(const Blob& other) const noexcept {
    return !(*this == other);
}

std::vector<std::uint32_t>::iterator
Blob::begin() noexcept {
    return pixelKeys_.begin();
}

std::vector<std::uint32_t>::iterator
Blob::end() noexcept {
    return pixelKeys_.end();
}

std::vector<std::uint32_t>::const_iterator
Blob::cbegin() const noexcept {
    return pixelKeys_.cbegin();
}

std::vector<std::uint32_t>::const_iterator
Blob::cend() const noexcept {
    return pixelKeys_.cend();
}

void Blob::addPixel(const Pixel& pixel) noexcept {
    pixelKeys_.push_back(pixel.getX() * 256 + pixel.getY());
}

void Blob::addPixelKey(const std::uint32_t key) noexcept {
    pixelKeys_.push_back(key);
}

std::ostream& operator<<(std::ostream& os, const Blob& blob) noexcept {
    os << "Blob keys:\n";
    for (const auto& key : blob.pixelKeys_) {
        os << key << ", ";
    }
    return os;
}

} // lucid