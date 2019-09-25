/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef KAGOME_INMEM_KEY_REPOSITORY_HPP
#define KAGOME_INMEM_KEY_REPOSITORY_HPP

#include <unordered_map>

#include "crypto/key.hpp"
#include "peer/key_repository.hpp"

namespace libp2p::peer {

  class InmemKeyRepository : public KeyRepository {
   public:
    ~InmemKeyRepository() override = default;

    InmemKeyRepository();

    void clear(const PeerId &p) override;

    outcome::result<PubVecPtr> getPublicKeys(const PeerId &p) override;

    outcome::result<void> addPublicKey(const PeerId &p,
                                       const crypto::PublicKey &pub) override;

    outcome::result<KeyPairVecPtr> getKeyPairs() override;

    outcome::result<void> addKeyPair(const KeyPair &kp) override;

    std::unordered_set<PeerId> getPeers() const override;

   private:
    std::unordered_map<PeerId, PubVecPtr> pub_;
    KeyPairVecPtr kp_;
  };

}  // namespace libp2p::peer

#endif  // KAGOME_INMEM_KEY_REPOSITORY_HPP