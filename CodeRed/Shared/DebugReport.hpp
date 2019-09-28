#pragma once

#include "Enum/DebugType.hpp"

#include <vector>
#include <string>

namespace CodeRed {
	
	class DebugReport final {
	public:
		using Type = DebugType;
		const static size_t MaxMessages = 10;
	public:
		static void warning(
			const DebugType& type,
			const std::vector<std::string>& messages);

		static void warning(
			const std::string& message);

		static void warning(
			const std::string& format,
			const std::vector<std::string>& messages);

		static void error(
			const std::string& message);

		static void error(
			const std::string& format,
			const std::vector<std::string>& messages);

		static void message(
			const std::string& message);
	private:
		static void output(const std::string& text);
		
		static auto select(const Type type) -> std::string;

		static auto push(
			const std::string& message_template, 
			const std::vector<std::string>& messages) -> std::string;
		
		template<typename T>
		friend class InvalidException;
		template<typename T>
		friend class ZeroException;
		friend class FailedException;
	};
	
}
