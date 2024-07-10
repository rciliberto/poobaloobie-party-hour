struct VS_INPUT
{
    float4 position : POSITION;
    float2 uv : TEXCOORD;
    float4 color : COLOR;
    int data1: DATA1_;
    // s8 texture_index
    // u8 type
    // u8 sampler_index
    // u8
};

struct PS_INPUT
{
    float4 position : SV_POSITION;
    float2 uv : TEXCOORD0;
    float4 color : COLOR;
    int texture_index: TEXTURE_INDEX;
    int type: TYPE;
    int sampler_index: SAMPLER_INDEX;
};

PS_INPUT vs_main(VS_INPUT input)
{
    PS_INPUT output;
    output.position = input.position;
    output.uv = input.uv;
    output.color = input.color;
    output.texture_index = (input.data1) & 0xFF;
    output.type          = (input.data1 >> 8) & 0xFF;
    output.sampler_index = (input.data1 >> 16) & 0xFF;
    return output;
}

// #Magicvalue
Texture2D textures[32] : register(t0);
SamplerState image_sampler_0 : register(s0);
SamplerState image_sampler_1 : register(s1);
SamplerState image_sampler_2 : register(s2);
SamplerState image_sampler_3 : register(s3);

float4 sample_texture(int texture_index, int sampler_index, float2 uv) {
	// I love hlsl
	if (sampler_index == 0) {
		if (texture_index ==  0)       return textures[0].Sample(image_sampler_0, uv);
		else if (texture_index ==  1)  return textures[1].Sample(image_sampler_0, uv);
		else if (texture_index ==  2)  return textures[2].Sample(image_sampler_0, uv);
		else if (texture_index ==  3)  return textures[3].Sample(image_sampler_0, uv);
		else if (texture_index ==  4)  return textures[4].Sample(image_sampler_0, uv);
		else if (texture_index ==  5)  return textures[5].Sample(image_sampler_0, uv);
		else if (texture_index ==  6)  return textures[6].Sample(image_sampler_0, uv);
		else if (texture_index ==  7)  return textures[7].Sample(image_sampler_0, uv);
		else if (texture_index ==  8)  return textures[8].Sample(image_sampler_0, uv);
		else if (texture_index ==  9)  return textures[9].Sample(image_sampler_0, uv);
		else if (texture_index ==  10) return textures[10].Sample(image_sampler_0, uv);
		else if (texture_index ==  11) return textures[11].Sample(image_sampler_0, uv);
		else if (texture_index ==  12) return textures[12].Sample(image_sampler_0, uv);
		else if (texture_index ==  13) return textures[13].Sample(image_sampler_0, uv);
		else if (texture_index ==  14) return textures[14].Sample(image_sampler_0, uv);
		else if (texture_index ==  15) return textures[15].Sample(image_sampler_0, uv);
		else if (texture_index ==  16) return textures[16].Sample(image_sampler_0, uv);
		else if (texture_index ==  17) return textures[17].Sample(image_sampler_0, uv);
		else if (texture_index ==  18) return textures[18].Sample(image_sampler_0, uv);
		else if (texture_index ==  19) return textures[19].Sample(image_sampler_0, uv);
		else if (texture_index ==  20) return textures[20].Sample(image_sampler_0, uv);
		else if (texture_index ==  21) return textures[21].Sample(image_sampler_0, uv);
		else if (texture_index ==  22) return textures[22].Sample(image_sampler_0, uv);
		else if (texture_index ==  23) return textures[23].Sample(image_sampler_0, uv);
		else if (texture_index ==  24) return textures[24].Sample(image_sampler_0, uv);
		else if (texture_index ==  25) return textures[25].Sample(image_sampler_0, uv);
		else if (texture_index ==  26) return textures[26].Sample(image_sampler_0, uv);
		else if (texture_index ==  27) return textures[27].Sample(image_sampler_0, uv);
		else if (texture_index ==  28) return textures[28].Sample(image_sampler_0, uv);
		else if (texture_index ==  29) return textures[29].Sample(image_sampler_0, uv);
		else if (texture_index ==  30) return textures[30].Sample(image_sampler_0, uv);
		else if (texture_index ==  31) return textures[31].Sample(image_sampler_0, uv);
	} else if (sampler_index == 1) {
		if (texture_index ==  0)       return textures[0].Sample(image_sampler_1, uv);
		else if (texture_index ==  1)  return textures[1].Sample(image_sampler_1, uv);
		else if (texture_index ==  2)  return textures[2].Sample(image_sampler_1, uv);
		else if (texture_index ==  3)  return textures[3].Sample(image_sampler_1, uv);
		else if (texture_index ==  4)  return textures[4].Sample(image_sampler_1, uv);
		else if (texture_index ==  5)  return textures[5].Sample(image_sampler_1, uv);
		else if (texture_index ==  6)  return textures[6].Sample(image_sampler_1, uv);
		else if (texture_index ==  7)  return textures[7].Sample(image_sampler_1, uv);
		else if (texture_index ==  8)  return textures[8].Sample(image_sampler_1, uv);
		else if (texture_index ==  9)  return textures[9].Sample(image_sampler_1, uv);
		else if (texture_index ==  10) return textures[10].Sample(image_sampler_1, uv);
		else if (texture_index ==  11) return textures[11].Sample(image_sampler_1, uv);
		else if (texture_index ==  12) return textures[12].Sample(image_sampler_1, uv);
		else if (texture_index ==  13) return textures[13].Sample(image_sampler_1, uv);
		else if (texture_index ==  14) return textures[14].Sample(image_sampler_1, uv);
		else if (texture_index ==  15) return textures[15].Sample(image_sampler_1, uv);
		else if (texture_index ==  16) return textures[16].Sample(image_sampler_1, uv);
		else if (texture_index ==  17) return textures[17].Sample(image_sampler_1, uv);
		else if (texture_index ==  18) return textures[18].Sample(image_sampler_1, uv);
		else if (texture_index ==  19) return textures[19].Sample(image_sampler_1, uv);
		else if (texture_index ==  20) return textures[20].Sample(image_sampler_1, uv);
		else if (texture_index ==  21) return textures[21].Sample(image_sampler_1, uv);
		else if (texture_index ==  22) return textures[22].Sample(image_sampler_1, uv);
		else if (texture_index ==  23) return textures[23].Sample(image_sampler_1, uv);
		else if (texture_index ==  24) return textures[24].Sample(image_sampler_1, uv);
		else if (texture_index ==  25) return textures[25].Sample(image_sampler_1, uv);
		else if (texture_index ==  26) return textures[26].Sample(image_sampler_1, uv);
		else if (texture_index ==  27) return textures[27].Sample(image_sampler_1, uv);
		else if (texture_index ==  28) return textures[28].Sample(image_sampler_1, uv);
		else if (texture_index ==  29) return textures[29].Sample(image_sampler_1, uv);
		else if (texture_index ==  30) return textures[30].Sample(image_sampler_1, uv);
		else if (texture_index ==  31) return textures[31].Sample(image_sampler_1, uv);
	} else if (sampler_index == 2) {
		if (texture_index ==  0)       return textures[0].Sample(image_sampler_2, uv);
		else if (texture_index ==  1)  return textures[1].Sample(image_sampler_2, uv);
		else if (texture_index ==  2)  return textures[2].Sample(image_sampler_2, uv);
		else if (texture_index ==  3)  return textures[3].Sample(image_sampler_2, uv);
		else if (texture_index ==  4)  return textures[4].Sample(image_sampler_2, uv);
		else if (texture_index ==  5)  return textures[5].Sample(image_sampler_2, uv);
		else if (texture_index ==  6)  return textures[6].Sample(image_sampler_2, uv);
		else if (texture_index ==  7)  return textures[7].Sample(image_sampler_2, uv);
		else if (texture_index ==  8)  return textures[8].Sample(image_sampler_2, uv);
		else if (texture_index ==  9)  return textures[9].Sample(image_sampler_2, uv);
		else if (texture_index ==  10) return textures[10].Sample(image_sampler_2, uv);
		else if (texture_index ==  11) return textures[11].Sample(image_sampler_2, uv);
		else if (texture_index ==  12) return textures[12].Sample(image_sampler_2, uv);
		else if (texture_index ==  13) return textures[13].Sample(image_sampler_2, uv);
		else if (texture_index ==  14) return textures[14].Sample(image_sampler_2, uv);
		else if (texture_index ==  15) return textures[15].Sample(image_sampler_2, uv);
		else if (texture_index ==  16) return textures[16].Sample(image_sampler_2, uv);
		else if (texture_index ==  17) return textures[17].Sample(image_sampler_2, uv);
		else if (texture_index ==  18) return textures[18].Sample(image_sampler_2, uv);
		else if (texture_index ==  19) return textures[19].Sample(image_sampler_2, uv);
		else if (texture_index ==  20) return textures[20].Sample(image_sampler_2, uv);
		else if (texture_index ==  21) return textures[21].Sample(image_sampler_2, uv);
		else if (texture_index ==  22) return textures[22].Sample(image_sampler_2, uv);
		else if (texture_index ==  23) return textures[23].Sample(image_sampler_2, uv);
		else if (texture_index ==  24) return textures[24].Sample(image_sampler_2, uv);
		else if (texture_index ==  25) return textures[25].Sample(image_sampler_2, uv);
		else if (texture_index ==  26) return textures[26].Sample(image_sampler_2, uv);
		else if (texture_index ==  27) return textures[27].Sample(image_sampler_2, uv);
		else if (texture_index ==  28) return textures[28].Sample(image_sampler_2, uv);
		else if (texture_index ==  29) return textures[29].Sample(image_sampler_2, uv);
		else if (texture_index ==  30) return textures[30].Sample(image_sampler_2, uv);
		else if (texture_index ==  31) return textures[31].Sample(image_sampler_2, uv);
	} else if (sampler_index == 3) {
		if (texture_index ==  0)       return textures[0].Sample(image_sampler_3, uv);
		else if (texture_index ==  1)  return textures[1].Sample(image_sampler_3, uv);
		else if (texture_index ==  2)  return textures[2].Sample(image_sampler_3, uv);
		else if (texture_index ==  3)  return textures[3].Sample(image_sampler_3, uv);
		else if (texture_index ==  4)  return textures[4].Sample(image_sampler_3, uv);
		else if (texture_index ==  5)  return textures[5].Sample(image_sampler_3, uv);
		else if (texture_index ==  6)  return textures[6].Sample(image_sampler_3, uv);
		else if (texture_index ==  7)  return textures[7].Sample(image_sampler_3, uv);
		else if (texture_index ==  8)  return textures[8].Sample(image_sampler_3, uv);
		else if (texture_index ==  9)  return textures[9].Sample(image_sampler_3, uv);
		else if (texture_index ==  10) return textures[10].Sample(image_sampler_3, uv);
		else if (texture_index ==  11) return textures[11].Sample(image_sampler_3, uv);
		else if (texture_index ==  12) return textures[12].Sample(image_sampler_3, uv);
		else if (texture_index ==  13) return textures[13].Sample(image_sampler_3, uv);
		else if (texture_index ==  14) return textures[14].Sample(image_sampler_3, uv);
		else if (texture_index ==  15) return textures[15].Sample(image_sampler_3, uv);
		else if (texture_index ==  16) return textures[16].Sample(image_sampler_3, uv);
		else if (texture_index ==  17) return textures[17].Sample(image_sampler_3, uv);
		else if (texture_index ==  18) return textures[18].Sample(image_sampler_3, uv);
		else if (texture_index ==  19) return textures[19].Sample(image_sampler_3, uv);
		else if (texture_index ==  20) return textures[20].Sample(image_sampler_3, uv);
		else if (texture_index ==  21) return textures[21].Sample(image_sampler_3, uv);
		else if (texture_index ==  22) return textures[22].Sample(image_sampler_3, uv);
		else if (texture_index ==  23) return textures[23].Sample(image_sampler_3, uv);
		else if (texture_index ==  24) return textures[24].Sample(image_sampler_3, uv);
		else if (texture_index ==  25) return textures[25].Sample(image_sampler_3, uv);
		else if (texture_index ==  26) return textures[26].Sample(image_sampler_3, uv);
		else if (texture_index ==  27) return textures[27].Sample(image_sampler_3, uv);
		else if (texture_index ==  28) return textures[28].Sample(image_sampler_3, uv);
		else if (texture_index ==  29) return textures[29].Sample(image_sampler_3, uv);
		else if (texture_index ==  30) return textures[30].Sample(image_sampler_3, uv);
		else if (texture_index ==  31) return textures[31].Sample(image_sampler_3, uv);
	}
	
	return float4(1.0, 0.0, 0.0, 1.0);
}



#define QUAD_TYPE_REGULAR 0
#define QUAD_TYPE_TEXT 1

float4 ps_main(PS_INPUT input) : SV_TARGET
{
	if (input.type == QUAD_TYPE_REGULAR) {
		if (input.texture_index >= 0 && input.texture_index < 32 && input.sampler_index >= 0  && input.sampler_index <= 3) {
			return sample_texture(input.texture_index, input.sampler_index, input.uv)*input.color;
		} else {
			return input.color;
		}
	} else if (input.type == QUAD_TYPE_TEXT) {
		if (input.texture_index >= 0 && input.texture_index < 32 && input.sampler_index >= 0  && input.sampler_index <= 3) {
			float alpha = sample_texture(input.texture_index, input.sampler_index, input.uv).x;
			return float4(1.0, 1.0, 1.0, alpha)*input.color;
		} else {
			return input.color;
		}
	}
	return float4(0.0, 1.0, 0.0, 1.0);
}