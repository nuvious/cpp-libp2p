/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <vector>

#include <boost/operators.hpp>
#include <libp2p/multi/multibase_codec.hpp>
#include <libp2p/multi/multicodec_type.hpp>
#include <libp2p/multi/multihash.hpp>

namespace libp2p::multi {

  /**
   * A CID is a self-describing content-addressed identifier. It uses
   * cryptographic hashes to achieve content addressing. It uses several
   * multiformats to achieve flexible self-description, namely multihash for
   * hashes, multicodec for data content types, and multibase to encode the CID
   * itself into strings. Concretely, it's a typed content address: a tuple of
   * (content-type, content-address).
   *
   * @note multibase may be omitted in non text-based protocols and is generally
   * needed only for CIDs serialized to a string, so it is not present in this
   * structure
   */
  struct ContentIdentifier
      : public boost::equality_comparable<ContentIdentifier> {
    enum class Version { V0 = 0, V1 = 1 };

    ContentIdentifier(Version version,
                      MulticodecType::Code content_type,
                      Multihash content_address);

    bool operator==(const ContentIdentifier &c) const;
    bool operator<(const ContentIdentifier &c) const;

    Version version;
    MulticodecType::Code content_type;
    Multihash content_address;
  };

}  // namespace libp2p::multi
