/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <set>
#include <unordered_set>

#include <libp2p/basic/garbage_collectable.hpp>
#include <libp2p/peer/peer_id.hpp>
#include <libp2p/peer/protocol.hpp>

namespace libp2p::peer {

  /**
   * @brief Storage for mapping between peer and its known protocols.
   */
  class ProtocolRepository : public basic::GarbageCollectable {
   public:
    ~ProtocolRepository() override = default;

    /**
     * @brief Add protocols to a peer.
     * param p peer
     * @param ms list of protocols
     * @return peer error, if no peer {@param p} found
     */
    virtual outcome::result<void> addProtocols(
        const PeerId &p, std::span<const ProtocolName> ms) = 0;

    /**
     * @brief Removes protocols from a peer.
     * @param p peer
     * @param ms list of protocols
     * @return peer error, if no peer {@param p} found
     */
    virtual outcome::result<void> removeProtocols(
        const PeerId &p, std::span<const ProtocolName> ms) = 0;

    /**
     * @brief Get all supported protocols by given peer {@param p}
     * @param p peer
     * @return list of protocols (may be empty) or peer error, if no peer
     * @param p} found
     */
    virtual outcome::result<std::vector<ProtocolName>> getProtocols(
        const PeerId &p) const = 0;

    /**
     * @brief Calculates set intersection between {@param protocols} and stored
     * protocols.
     * @param p peer
     * @param protocols check if given protocols are supported by a peer
     * @return list of supported protocols (may be empty) or peer error, if no
     * peer {@param p} found
     */
    virtual outcome::result<std::vector<ProtocolName>> supportsProtocols(
        const PeerId &p, const std::set<ProtocolName> &protocols) const = 0;

    /**
     * @brief Remove all associated protocols for given peer
     * @param p peer
     *
     * @note does not remove peer from a list of known peers. So, peer can
     * contain "0 protocols".
     */
    virtual void clear(const PeerId &p) = 0;

    /**
     * @brief Returns set of peer ids known by this repository.
     * @return unordered set of peers
     */
    virtual std::unordered_set<PeerId> getPeers() const = 0;
  };

}  // namespace libp2p::peer
