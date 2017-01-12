/**
 * Copyright (C) 2015-2016 Virgil Security Inc.
 *
 * Lead Maintainer: Virgil Security Inc. <support@virgilsecurity.com>
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     (1) Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *     (2) Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 *     (3) Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ''AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <cli/argument/ArgumentTransformer.h>

#include <cli/api/api.h>

#include <cli/command/KeygenCommand.h>
#include <cli/command/KeyToPubCommand.h>
#include <cli/command/EncryptCommand.h>
#include <cli/command/DecryptCommand.h>

#include <cli/error/ArgumentError.h>

using cli::argument::ArgumentTransformer;
using namespace cli::command;

std::unique_ptr<Command> ArgumentTransformer<Command>::transform() const {
    const auto commandName = argumentValue_;
    if (commandName == arg::value::VIRGIL_COMMAND_KEYGEN) {
        return std::make_unique<KeygenCommand>();
    } else if (commandName == arg::value::VIRGIL_COMMAND_KEY2PUB) {
        return std::make_unique<KeyToPubCommand>();
    } else if (commandName == arg::value::VIRGIL_COMMAND_ENCRYPT) {
        return std::make_unique<EncryptCommand>();
    } else if (commandName == arg::value::VIRGIL_COMMAND_DECRYPT) {
        return std::make_unique<DecryptCommand>();
    }
    throw error::ArgumentValueError(arg::COMMAND, commandName);
}