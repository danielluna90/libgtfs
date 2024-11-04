#pragma once

#include <string>

enum StatusCode {
  OK,
  ERROR,
};

enum ErrorCode {
  NOT_AVAILABLE,

  PATH_NOT_DIRECTORY,
  REQUIRED_FILE_MISSING
};

class Result {
public:
  explicit Result(const StatusCode code);
  explicit Result(const StatusCode code, const ErrorCode error);

  bool Success() { return code == StatusCode::OK; }

  ErrorCode GetErrorCode() const { return error; }

  const std::string ToString() const;
  friend std::ostream& operator<<(std::ostream& os, const Result& res);

private:
  const std::string StatusCodeToString() const;
  const std::string ErrorCodeToString() const;

private:
  StatusCode code;
  ErrorCode error;
};