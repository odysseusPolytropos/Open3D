// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2018-2021 www.open3d.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#pragma once

#include <string>

namespace open3d {
namespace data {

/// \brief Computes SHA256 Hash for the given file.
/// \param file_path Path to the file.
std::string GetSHA256(const std::string& file_path);

/// \brief Function to download the file from URL.
/// \param url File URL.
/// \param data_root Open3D data root directory. See open3d::data::Dataset
/// class for more information. If empty, the default data root is used.
/// \param prefix The file will be downloaded to `data_root/prefix`.
/// Typically we group data file by dataset, e.g., "kitti", "rgbd", etc. If
/// empty, the file will be downloaded to `data_root` directly.
/// \param always_download If `false`, it will skip download if the file is
/// present in the given location with given file name and expected SHA256SUM.
/// It will trigger download if these conditions are not met. If `true`, it will
/// always trigger download and over-write the file if present. Default: `true`.
/// \param sha256 SHA256SUM HASH value to verify the file after download. If
/// empty string is passed, the verification will be skipped. If
/// `always_download` is set to `false`, then it `SHA256` is a required
/// parameter.
/// \param print_progress Display progress bar for download.
bool DownloadFromURL(const std::string& url,
                     const std::string& sha256,
                     const std::string& data_root = "",
                     const std::string& prefix = "",
                     const bool always_download = true,
                     const bool print_progress = false);

}  // namespace data
}  // namespace open3d
