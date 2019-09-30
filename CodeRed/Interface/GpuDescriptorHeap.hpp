#pragma once

#include "../Shared/Noncopyable.hpp"

#include <memory>

namespace CodeRed {

	class GpuResource;
	class GpuTexture;
	class GpuBuffer;

	class GpuLogicalDevice;
	class GpuResourceLayout;
	
	class GpuDescriptorHeap : public Noncopyable {
	protected:
		explicit GpuDescriptorHeap(
			const std::shared_ptr<GpuLogicalDevice>& device,
			const std::shared_ptr<GpuResourceLayout>& resource_layout);

		~GpuDescriptorHeap() = default;
	public:
		void bindResource(
			const size_t index,
			const std::shared_ptr<GpuResource>& resource);

		virtual void bindTexture(
			const size_t index,
			const std::shared_ptr<GpuTexture>& texture) = 0;

		virtual void bindBuffer(
			const size_t index,
			const std::shared_ptr<GpuBuffer>& buffer) = 0;
	
		auto layout() const noexcept -> std::shared_ptr<GpuResourceLayout> { return mResourceLayout; }
	protected:
		std::shared_ptr<GpuResourceLayout> mResourceLayout;
		std::shared_ptr<GpuLogicalDevice> mDevice;
	};
	
}