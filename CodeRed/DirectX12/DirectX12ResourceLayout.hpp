#pragma once

#include "../Interface/GpuResourceLayout.hpp"
#include "../Shared/IdentityAllocator.hpp"
#include "DirectX12Utility.hpp"

#include <map>

#ifdef __ENABLE__DIRECTX12__

namespace CodeRed {

	class DirectX12ResourceLayout final : public GpuResourceLayout {
	public:
		explicit DirectX12ResourceLayout(
			const std::shared_ptr<GpuLogicalDevice>& device,
			const std::vector<ResourceLayoutElement>& elements,
			const std::vector<SamplerLayoutElement>& samplers,
			const size_t maxBindResources = 1 << 10);

		~DirectX12ResourceLayout() = default;

		void reset() override;
		
		void bindTexture(
			const size_t index,
			const std::shared_ptr<GpuTexture>& resource) override;

		void bindBuffer(
			const size_t index,
			const std::shared_ptr<GpuBuffer>& resource) override;

		void unbindResource(
			const std::shared_ptr<GpuResource>& resource) override;
		
		auto rootSignature() const noexcept -> WRL::ComPtr<ID3D12RootSignature> { return mRootSignature; }

		auto descriptorHeap() const noexcept -> WRL::ComPtr<ID3D12DescriptorHeap> { return mDescriptorHeap; }

		auto handle(const std::shared_ptr<GpuResource>& resource) 
			-> D3D12_GPU_DESCRIPTOR_HANDLE;
	private:
		using Container = std::map<std::shared_ptr<GpuResource>, D3D12_GPU_DESCRIPTOR_HANDLE>;
		
		WRL::ComPtr<ID3D12RootSignature> mRootSignature;
		WRL::ComPtr<ID3D12DescriptorHeap> mDescriptorHeap;

		IdentityAllocator<Container, size_t> mIdentityAllocator;

		size_t mDescriptorSize = 0;
	};
	
}

#endif