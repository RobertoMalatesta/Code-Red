# Render Pass

A render pass is a stage in graphics pipeline of drawing. In a render pass, we will set the target we will render to and record some draw commands.

## Frame Buffer

A frame buffer is a set of render targets with a depth stencil buffer. Frame buffer defined which texture we will render to, which texture we will use for depth test or stencil.

### Render Target

A texture we will render to called render target. A render target is a part of frame buffer.

### Depth Stencil

You can learn more from DirectX and Vulkan.

## Render Pass

`GpuRenderPass` is a interface to describe how we begin a render pass. For example, the layout of render target when we begin a render pass and when we end a render pass, if we need clear the render target, if we need clear the depth-stencil buffer.

### Attachment

```C++
struct Attachment {
    PixelFormat Format;
    MultiSample Sample;

    ResourceLayout InitialLayout;
    ResourceLayout FinalLayout;

    AttachmentLoad Load;
    AttachmentStore Store;

    AttachmentLoad StencilLoad;
    AttachmentStore StencilStore;
};
```

- `Format` : format of texture.
- `Sample` : sample per pixel of texture.
- `InitialLayout` : the layout of texture when render pass begin.
- `FinalLayout` : the layout of texture when render pass end.
- `Load` : the operator how we load texture(clear, load...).
- `Store` : the operator how we store pixel we render to texture(store...).
- `StencilLoad` : operator for stencil.
- `StencilStore` : operator for stencil.

The second parameter of render pass constructer is `colors`, an array of `Attachment`. It describe the property of frame buffer's render targets. 
The third parameter of render pass constructer is `depth`, a struct of `Attachment`. It describe the property of frame buffer's depth stencil.

### Attachment Index

The index of attachment is used for multi-render target. If you have two color attachments and one depth attachments. The first two attachments are color attachments and the last is depth attachments.

The first color attachment and color clear value will used for first render target in frame buffer, the second for second. 

### Begin Render Pass

When we begin a render pass, we need to set a render pass and a frame buffer. The frame buffer's format must be same as format of render pass's attachments. If we do not have depth stencil buffer, the depth stencil attachment can be `std::nullopt`.

After setting a render pass and frame buffer, we will translate the layout of render target or depth stencil to `InitialLayout`. If the `Load` is clear, we will use the `GpuRenderPass::clearColor()` or `GpuRenderPass::clearDepth()` to get clear value and clear the render target or depth stencil.

### End Render Pass

When we do not need to render to the frame buffer we set at begin, we need to end a render pass. And we will translate the layout of render target or depth stencil to `FinalLayout`.
