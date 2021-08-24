#pragma once


#ifndef __INCLUDE__PRELIM__PARSER_INTERFACE_H
#define __INCLUDE__PRELIM__PARSER_INTERFACE_H

#include <string>
#include <vector>
#include <stdexcept>

#include "tokenizer.hpp"

class parser_interface
{
public:
	parser_interface() {}
	~parser_interface() {}


	//	Getters
	unsigned int index()
	{
		return m_nIndex;
	}


	token current()
	{
		if (m_bAtEnd) {
			throw std::out_of_range("uParserInterfaceError: EOF while calling current.");
		}
		return m_current;
	}


	bool atEnd()
	{
		return m_bAtEnd;
	}


	std::vector<token> tokens()
	{
		return m_tokens;
	}


	// Setters
	void end()
	{
		m_bAtEnd = true;
	}


	/*	Methods */

	bool init(std::vector<token> tokens)
	{
		reset();
		m_tokens = tokens;
		if (m_tokens.size() == 0) {
			m_bAtEnd = true;
			return false;
		}
		m_current = m_tokens.at(0);
		return true;
	}


	void reset()
	{
		m_nIndex = 0;
		m_tokens.clear();
		m_bAtEnd = false;
	}


	void advance()
	{
		if (m_bAtEnd) {
			throw std::out_of_range("ParserInterfaceError: Attempted to advance past end.");
		}
		m_nIndex++;
		if (m_nIndex >= m_tokens.size()) {
			m_bAtEnd = true;
			return;
		}
		m_current = m_tokens.at(m_nIndex);
	}


	bool match(token token, std::string type)
	{
		if (token.type() == type) {
			return true;
		}
		return false;
	}


	bool match(std::string type)
	{
		if (m_bAtEnd) {
			return false;
		}
		if (current().type() == type) {
			advance();
			return true;
		}
		return false;
	}


	bool lexMatch(token token, std::string value)
	{
		if (token.lexeme() == value) {
			return true;
		}
		return false;
	}


	bool lexMatch(std::string value)
	{
		if (current().lexeme() == value) {
			advance();
			return true;
		}
		return false;
	}


	token consume(std::string type, std::string message)
	{
		if (m_bAtEnd) {
			throw std::out_of_range("ParserInterfaceError: " + message);
		}
		if (match(current(), type)) {
			advance();
			return previous("");
		}
		throw std::invalid_argument("ParserInterfaceError at token " + current().toStr() + ": " + message);
	}


	token previous(std::string message = "")
	{
		try {
			return m_tokens.at(m_nIndex - 1);
		}
		catch (std::out_of_range) {
			throw std::out_of_range("ParserInterfaceError: out of range; " + message);
		}
	}


	bool exists(int look)
	{
		if (m_nIndex + look < m_tokens.size()) {
			return true;
		}
		return false;
	}

private:
	//	Members

	unsigned int m_nIndex{ 0 };
	bool m_bAtEnd{ false };
	token m_current;
	std::vector<token> m_tokens;

};




#endif // end #ifndef __INCLUDE_PARSERINTERFACE_H