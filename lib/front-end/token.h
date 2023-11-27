#ifndef TOKEN_H
#define TOKEN_H

#include <cstddef>
#include <iostream>

#include "absl/strings/string_view.h"
#include "absl/status/statusor.h"
#include "lib/frontend/utils/sizes.h"

namespace ascc::frontend {

enum class TokenType {
  kPlus,
  kPlusPlus,
  kMinus,
  kMinusMinus,
  kLeftParen,
  kLessThan,
  kGreaterThan,
  kLessThanEqual,
  kGreaterThanEqual,
  kLeftShift,
  kRightShift,
  kDot,
  kArrow,
  kStar,
  kSlash,
  kEqual,
  kEqualEqual,
  kSemicolon,
  kColon,
  kRightParen,
  kLeftCurly,
  kRightCurly,
  kLeftBracket,
  kRightBracket,
  kComma,
  kReturn,
  kInt,
  kChar,
  kVoid,
  kIdentifier,
  kConstant,
  kConstantUint8,
  kConstantUint16,
  kConstantUint32,
  kConstantUint64,
  kConstantInt8,
  kConstantInt16,
  kConstantInt32,
  kConstantInt64,
  kAmpersand,
  kBang,
  kLogicalOr,
  kLogicalAnd,
  kLexicalError,
  kErrorType,
};

class Token {
 public:
  Token(size_t start, size_t len, size_t line, TokenType type);
  absl::string_view from_source(absl::string_view src) const;

  static absl::string_view type_as_str(TokenType type);

  static absl::StatusOr<Size> to_reg_size(TokenType type);
  friend std::ostream& operator<<(std::ostream& os, const Token& token);
  inline TokenType type() const { return _type; }

  inline size_t start() const { return _start; }
  inline size_t len() const { return _len; }
  inline size_t line() const { return _line; }

 private:
  size_t _start;    // Starting position of the token in the source.
  size_t _len;      // Length of the token.
  size_t _line;     // Line number where the token appears in the source.
  TokenType _type;  // Type of the token.
};

}  // namespace ascc::frontend

#endif  // TOKEN_H
