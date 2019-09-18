#pragma once

#ifdef __ENABLE__DIRECTX12__

#include <wrl/client.h>
#include <dxgi1_5.h>
#include <d3d12.h>

#include <string>
#include <vector>

using namespace Microsoft;

namespace CodeRed {

	class Exception;

	enum class ShaderVisibility : UInt32;
	enum class CompareOperator : UInt32;
	enum class StencilOperator : UInt32;
	enum class ResourceLayout : UInt32;
	enum class FilterOptions : UInt32;
	enum class BlendOperator : UInt32;
	enum class ResourceUsage : UInt32;
	enum class ResourceType : UInt32;
	enum class PixelFormat : UInt32;
	enum class AddressMode : UInt32;
	enum class BlendFactor : UInt32;
	enum class BorderColor : UInt32;
	enum class MemoryHeap : UInt32;
	enum class Dimension : UInt32;
	enum class ColorMask : UInt32;
	enum class FillMode : UInt32;
	enum class CullMode : UInt32;
	
	auto wideStringToMultiString(const std::wstring& wstring)->std::string;

	
	void throwIfFailed(HRESULT result, const Exception& exception);

	auto enumConvert(const FilterOptions filter) -> D3D12_FILTER;

	auto enumConvert(const AddressMode mode) -> D3D12_TEXTURE_ADDRESS_MODE;

	auto enumConvert(const BorderColor border) -> D3D12_STATIC_BORDER_COLOR;

	auto enumConvert(const ResourceType type) -> D3D12_ROOT_PARAMETER_TYPE;
	
	auto enumConvert(const ShaderVisibility visibility) -> D3D12_SHADER_VISIBILITY;

	auto enumConvert(const ResourceLayout layout) -> D3D12_RESOURCE_STATES;

	auto enumConvert(const ResourceUsage usage) -> D3D12_RESOURCE_FLAGS;

	auto enumConvert(const MemoryHeap heap) -> D3D12_HEAP_TYPE;

	auto enumConvert(const PixelFormat format) -> DXGI_FORMAT;

	auto enumConvert(const Dimension dimension) -> D3D12_RESOURCE_DIMENSION;

	auto enumConvert(const CompareOperator op) -> D3D12_COMPARISON_FUNC;

	auto enumConvert(const StencilOperator op) -> D3D12_STENCIL_OP;

	auto enumConvert(const BlendOperator op) -> D3D12_BLEND_OP;

	auto enumConvert(const BlendFactor factor) -> D3D12_BLEND;

	auto enumConvert(const ColorMask mask) -> D3D12_COLOR_WRITE_ENABLE;

	auto enumConvert(const FillMode mode) -> D3D12_FILL_MODE;

	auto enumConvert(const CullMode mode) -> D3D12_CULL_MODE;
}

#endif