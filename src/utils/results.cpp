#include "gtfs/utils/results.h"

Result::Result(const StatusCode code)
    : code(code), error(ErrorCode::NOT_AVAILABLE) {}

Result::Result(const StatusCode code, const ErrorCode error)
    : code(code), error(error) {}

const std::string Result::StatusCodeToString() const {
  switch (code) {
    case StatusCode::OK:
      return "OK";
    case StatusCode::ERROR:
    default:
      return "ERROR";
  }
}

const std::string Result::ErrorCodeToString() const {
  switch (error) {
    case ErrorCode::PATH_NOT_DIRECTORY:
      return "PATH IS NOT DIRECTORY";
    case ErrorCode::REQUIRED_FILE_MISSING:
      return "REQUIRED FILE IS MISSING";
    case ErrorCode::NOT_AVAILABLE:
    default:
      return "NOT AVAILABLE";
  }
}

const std::string Result::ToString() const {
  std::string res = std::string("Status: " + StatusCodeToString());

  if (code == StatusCode::ERROR) res += ", Error Code: " + ErrorCodeToString();

  return res;
}
