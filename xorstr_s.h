#pragma once
#include <type_traits>
#include <array>

namespace HashJic
{
	constexpr uint64_t val_64_const = 0xcbf29ce484222325;
	constexpr uint64_t prime_64_const = 0x100000001b3;

	constexpr uint64_t hash_str(const char* const str, const uint64_t value = val_64_const)
	{
		return (str[0] == '\0') ? value : hash_str(&str[1], (value ^ uint64_t(str[0])) * prime_64_const);
	}
}

#define RandomSeed(Min, Max)	(Min + (std::integral_constant<uint64_t, HashJic::hash_str(__TIME__)>::value % (Max - Min + 1)))

const uint8_t constexpr GlobalEncKey = static_cast<uint8_t>(RandomSeed(1, 0xFF));

constexpr uint8_t EncryptData(const uint8_t byteIn)
{
	return byteIn ^ GlobalEncKey;
}

static uint8_t confuseCT = 0;
__forceinline uint8_t DecryptByte(const uint8_t byteIn)
{
	return byteIn ^ (GlobalEncKey + confuseCT);
}

__forceinline constexpr char Encryptcharacter(const char character)
{
	return EncryptData(character);
}

__forceinline constexpr wchar_t Encryptcharacter(const wchar_t wideCharacter)
{
	return EncryptData((wideCharacter & 0xFF00) >> 8) << 8 | EncryptData(wideCharacter & 0x00FF);
}

__forceinline char Decryptcharacter(const char character)
{
	return DecryptByte(character);
}

__forceinline wchar_t Decryptcharacter(const wchar_t wideCharacter)
{
	return DecryptByte((wideCharacter & 0xFF00) >> 8) << 8 | DecryptByte(wideCharacter & 0x00FF);
}

template <typename T, size_t N>
class EncString
{
public:
	template<size_t... Index>
	constexpr EncString(const T(&str)[N], std::index_sequence<Index...>) noexcept
		: encBuffer{ { Encryptcharacter(str[Index])... } }, status{ false } {}

	__forceinline const T* decrypt() {
		
		for (volatile unsigned index = 0; index < N; index++)
		{
			encBuffer[index] = encBuffer[index] ^ confuseCT;
		}

		if (!status)
		{
			RecursiveExpand<N - 1>();
			status = true;
		}

		return const_cast<const T*>(encBuffer.data());
	}

private:
	bool status;
	std::array<T, N> encBuffer;

	template<int IndexN>
	__forceinline void RecursiveExpand() {
		encBuffer[IndexN] = Decryptcharacter(encBuffer[IndexN]);
		if constexpr (IndexN != 0) {
			RecursiveExpand<IndexN - 1>();
		}
	}
};

#define Enc(str) EncString(str, std::make_index_sequence<_countof(str)>{}).decrypt()