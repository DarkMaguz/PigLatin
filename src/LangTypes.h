/*
 * types.h
 *
 *  Created on: Dec 20, 2021
 *      Author: magnus
 */

#ifndef SRC_LANGTYPES_H_
#define SRC_LANGTYPES_H_

#include <string_view>
#include <map>
#include <array>

using std::literals::operator""sv;
#define VOWELS_DA "AEÉIOUYÆØÅaeéiouyæøå"sv
#define VOWELS_NO VOWELS_DA
#define VOWELS_SW "AEÉIOUYÅÄÖaeéiouyæøåäö"sv
#define VOWELS_EN "AEÉIOUaeéiou"sv
#define VOWELS_DE "AEÉIOUYÄÖÜaeéiouyäöü"sv

namespace lt
{

typedef enum {
	Danish,
	Norwegian,
	Sweedish,
	English,
	Deutsch
} lang_t;

typedef typeof(""sv) sv_t;
typedef std::array<bool, 256> boolArr_t;
typedef std::pair<const lang_t, const boolArr_t> langPair_t;

template<class T, int N, class Function, class V>
constexpr auto makeArray(Function f, V v)
{
	std::array<T, N> a {false};
  for (size_t i = 0; i < N; i++)
  	if (f(i, v))
  		a[i] = true;
	return a;
}

inline auto makeVCMap(void)
{
	constexpr auto isVowel = [](const char& letter, const sv_t& vowels) {
		for (const auto ch : vowels)
			if (letter == ch) return true;
		return false;
	};

	std::map<const lang_t, const boolArr_t> lMap = {
			langPair_t(Danish, makeVCArray<bool, 256>(isVowel, VOWELS_DA)),
			langPair_t(Norwegian, makeVCArray<bool, 256>(isVowel, VOWELS_NO)),
			langPair_t(Sweedish, makeVCArray<bool, 256>(isVowel, VOWELS_SW)),
			langPair_t(English, makeVCArray<bool, 256>(isVowel, VOWELS_EN)),
			langPair_t(Deutsch, makeVCArray<bool, 256>(isVowel, VOWELS_DE))
	};
	return lMap;
}

}  // namespace lt

#endif /* SRC_LANGTYPES_H_ */
