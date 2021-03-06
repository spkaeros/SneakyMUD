#pragma once
#include <iostream>
#include <functional>

namespace sneaky {
namespace IO {
class ByteStream {
public:
	ByteStream();
	void wrap(uint8_t* a_buf, int a_size);
	int8_t readSignedByte();
	uint8_t readUnsignedByte();
	void skip(const int& amount);
	std::function<int16_t(void)> readSignedShort;
	std::function<uint16_t(void)> readUnsignedShort;
	std::function<int32_t(void)> readSignedInt;
	std::function<uint32_t(void)> readUnsignedInt;
	const int& getPos();
	const int& getLen();
private:
	uint8_t* m_buf{ nullptr };
	int m_len{ 0 };
	int m_pos{ 0 };
};
}}