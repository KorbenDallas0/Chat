#pragma once
#include<string>
class Message
{
public:
    Message(const std::string& from, const std::string& to, const std::string& text);
    const std::string& getFrom() const noexcept;
    const std::string& getTo() const noexcept;
    const std::string& getText() const noexcept;
private:
    std::string _from;
    std::string _to;
    std::string _text;
};
