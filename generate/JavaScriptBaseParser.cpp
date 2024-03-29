#include "gcomm.h"
#include "JavaScriptParser.h"

using namespace antlr4;
using namespace PolydeucesEngine;

JavaScriptBaseParser::JavaScriptBaseParser(TokenStream *input) : Parser(input)
{
}

bool JavaScriptBaseParser::p(std::string str)
{
    return prev(str);
}

bool JavaScriptBaseParser::prev(std::string str)
{
    return _input->LT(-1)->getText() == str;
}

bool JavaScriptBaseParser::n(std::string str)
{
    return next(str);
}

bool JavaScriptBaseParser::next(std::string str)
{
    return _input->LT(1)->getText() == str;
}

bool JavaScriptBaseParser::notLineTerminator()
{
    return !here(JavaScriptParser::LineTerminator);
}

bool JavaScriptBaseParser::notOpenBraceAndNotFunction()
{
    int nextTokenType = _input->LT(1)->getType();
    return nextTokenType != JavaScriptParser::OpenBrace && nextTokenType != JavaScriptParser::Function;

}

bool JavaScriptBaseParser::closeBrace()
{
    return _input->LT(1)->getType() == JavaScriptParser::CloseBrace;
}

bool JavaScriptBaseParser::here(int type)
{
    // Get the token ahead of the current index.
    int possibleIndexEosToken = this->getCurrentToken()->getTokenIndex() - 1;
    auto ahead = _input->get(possibleIndexEosToken);

    // Check if the token resides on the HIDDEN channel and if it's of the
    // provided type.
    return (ahead->getChannel() == Lexer::HIDDEN) && (ahead->getType() == type);
}

bool JavaScriptBaseParser::lineTerminatorAhead()
{
    // Get the token ahead of the current index.
    int possibleIndexEosToken = this->getCurrentToken()->getTokenIndex() - 1;
    auto ahead = _input->get(possibleIndexEosToken);

    if (ahead->getChannel() != Lexer::HIDDEN) {
        // We're only interested in tokens on the HIDDEN channel.
        return false;
    }

    if (ahead->getType() == JavaScriptParser::LineTerminator) {
        // There is definitely a line terminator ahead.
        return true;
    }

    if (ahead->getType() == JavaScriptParser::WhiteSpaces) {
        // Get the token ahead of the current whitespaces.
        possibleIndexEosToken = this->getCurrentToken()->getTokenIndex() - 2;
        ahead = _input->get(possibleIndexEosToken);
    }

    // Get the token's text and type.
    std::string text = ahead->getText();
    int type = ahead->getType();

    // Check if the token is, or contains a line terminator.
    return (type == JavaScriptParser::MultiLineComment && (text.find("\r") != std::string::npos || text.find("\n") != std::string::npos)) ||
            (type == JavaScriptParser::LineTerminator);
}
