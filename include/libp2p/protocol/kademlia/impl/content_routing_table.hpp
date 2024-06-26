/**
 * Copyright Quadrivium LLC
 * All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <libp2p/event/bus.hpp>
#include <libp2p/protocol/kademlia/common.hpp>
#include <libp2p/protocol/kademlia/config.hpp>
#include <libp2p/protocol/kademlia/node_id.hpp>

namespace libp2p::event::protocol::kademlia {

  using ProvideContentChannel =
      channel_decl<struct ProvideContent,
                   std::pair<const libp2p::protocol::kademlia::ContentId &,
                             const libp2p::peer::PeerId &>>;

}  // namespace libp2p::event::protocol::kademlia

namespace libp2p::protocol::kademlia {

  /**
   * @class ContentRoutingTable
   */
  struct ContentRoutingTable {
    virtual ~ContentRoutingTable() = default;

    virtual void start() = 0;

    virtual void addProvider(const ContentId &key,
                             const peer::PeerId &peer) = 0;

    virtual std::vector<PeerId> getProvidersFor(const ContentId &key,
                                                size_t limit = 0) const = 0;
  };

}  // namespace libp2p::protocol::kademlia
