#pragma once

#include "DirectX12Utility.hpp"
#include "../Interface/GpuCommandQueue.hpp"

#ifdef __ENABLE__DIRECTX12__

namespace CodeRed {

	class DirectX12CommandQueue final : public GpuCommandQueue {
	public:
		explicit DirectX12CommandQueue(
			const std::shared_ptr<GpuLogicalDevice>& device);

		~DirectX12CommandQueue() = default;

		void execute(const std::vector<std::shared_ptr<GpuGraphicsCommandList>>& lists) override;

		void waitIdle() override;
		
		auto queue() const noexcept -> WRL::ComPtr<ID3D12CommandQueue> { return mCommandQueue; }
	private:
		WRL::ComPtr<ID3D12CommandQueue> mCommandQueue;
	};
	
}

#endif