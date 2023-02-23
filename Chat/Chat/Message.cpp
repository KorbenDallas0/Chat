#include "Message.hpp"

Message::Message(const std::string& from, const std::string& to, const std::string& text)
    : _from{ from }, _to{ to }, _text{ text } {}

const std::string& Message::getFrom() const noexcept { return _from; }
const std::string& Message::getTo() const noexcept { return _to; }
const std::string& Message::getText() const noexcept { return _text; }