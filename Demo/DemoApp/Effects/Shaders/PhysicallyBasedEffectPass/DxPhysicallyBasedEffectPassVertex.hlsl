#pragma pack_matrix(row_major)

struct Transform3D
{
    matrix NormalTransform;
    matrix Projection;
    matrix Transform;
    matrix View;
};

struct Output
{
    float3 ViewPosition : POSITION0;
    float4 SVPosition : SV_POSITION;
    float3 Position : POSITION1;
    float3 Normal : NORMAL;
	float2 Texcoord : TEXCOORD;
	uint   InstanceId : SV_INSTANCEID;
};

StructuredBuffer<Transform3D> transforms : register(t2, space0);

Output main(
    float3 position : POSITION,
    float3 normal : NORMAL,
	float2 texcoord : TEXCOORD,
	uint   instanceId : SV_INSTANCEID)
{
    Output result;

    result.Position = mul(float4(position, 1.0f), transforms[instanceId].Transform).xyz;
    result.ViewPosition = mul(float4(result.Position, 1.0f), transforms[instanceId].View).xyz;
    result.SVPosition = mul(float4(result.ViewPosition, 1.0f), transforms[instanceId].Projection);
    result.Normal = mul(float4(normal, 1.0f), transforms[instanceId].NormalTransform).xyz;
	result.Texcoord = texcoord;
	result.InstanceId = instanceId;

    return result;
}