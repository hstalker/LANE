///////////////////////////////////////////////////////////////////////////////
/// \file LaneFile.hpp
/// \author Hector Stalker <hstalker0@gmail.com>
/// \version 0.1
///
/// \brief Handles the intermediate file format for LANE raw data
///
/// \copyright Copyright (c) 2014, Hector Stalker. All rights reserved.
/// This file is under the Simplified (2-clause) BSD license
/// For conditions of distribution and use, see:
/// http://opensource.org/licenses/BSD-2-Clause
/// or read the 'LICENSE.md' file distributed with this code

#ifndef LUCID_LANEFILE_HPP
#define LUCID_LANEFILE_HPP

#include <string>
#include <map>
#include <vector>
#include <ostream>
#include <cstdint>
#include "Frame.hpp"
#include "Utils/Misc.hpp"

namespace lane {

///////////////////////////////////////////////////////////////////////////////
/// \brief Class for handling LANE intermedaite raw data files
class LANEFile final {
public:
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Constructor
    LANEFile() noexcept;
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Overloaded ostream operator for the LANEFile class
    /// \param fileName The name/path of the file to read in
    LANEFile(const std::string& fileName);
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Destructor
    ~LANEFile() noexcept;
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Copy constructor
    /// \param other Object to be copy constructed from
    LANEFile(const LANEFile& other);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Move constructor
    /// \param other Object to be move constructed from
    LANEFile(LANEFile&& other);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Copy assignment operator
    /// \param other Object to be copy assigned from
    LANEFile& operator=(const LANEFile& other);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Move assignment operator
    /// \param other Object to be move assigned from
    LANEFile& operator=(LANEFile&& other);

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Equality operator
    /// \param other Object to be compared against
    bool operator==(const LANEFile& other) const noexcept;

    ///////////////////////////////////////////////////////////////////////////
    /// \brief Inequality operator
    /// \param other Object to be compared against
    bool operator!=(const LANEFile& other) const noexcept;
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Reads in a LANE intermediate file
    /// \param fileName The name/path of the file to read in
    void read(const std::string& fileName);
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Writes out the stored information to a LANE intermediate file
    /// \param fileName The name/path of the file to write to
    void write(const std::string& fileName);
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Adds a frame object to internal storage
    /// \param frame A frame to add to the internal storage
    /// \param channelID The channelID to associate to the frame
    void addFrame(
        const lucid::Frame& frame,
        std::uint32_t channelID = 0
    ) noexcept;
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the frames associated with a channel
    /// \param channelID The ID of the channel to grab from
    /// \return A vector of frames
    std::vector<lucid::Frame> getFrames(
        const std::uint32_t channelID
    ) const noexcept;
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the file ID
    /// \param fileID The file ID to set
    void setFileID(const std::uint32_t fileID) noexcept;
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Sets the start time
    /// \param startTime The start time to set
    void setStartTime(const std::uint32_t startTime) noexcept;
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the file ID
    /// \return The file ID to associated with this file
    std::uint32_t getFileID() const noexcept;
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Gets the start time
    /// \return The start time associated to this file
    std::uint32_t getStartTime() const noexcept;
    
    ///////////////////////////////////////////////////////////////////////////
    /// \brief Overloaded ostream operator for the LANEFile class
    /// \param os The output stream
    /// \param file The LANE data file to stream out
    /// \return A reference to the ostream in use
    friend std::ostream& operator<<(
        std::ostream& os,
        const LANEFile& file
    ) noexcept;

private:
    void clear() noexcept;

    std::map<std::uint32_t, std::vector<lucid::Frame>> channels_;
    std::uint32_t startTime_;
    std::uint32_t fileID_;
};

} // lane

#endif // LUCID_LANEFILE_HPP
