#ifndef CC_PARTICLE_H
#define CC_PARTICLE_H
#include "Typedefs.h"
#include "Vectors.h"
#include "PackedCol.h"
#include "VertexStructs.h"
#include "2DStructs.h"
#include "GameStructs.h"
/* Represents particle effects, and manages rendering and spawning particles.
   Copyright 2014-2017 ClassicalSharp | Licensed under BSD-3
*/

typedef struct Particle_ {
	Vector3 Velocity;
	Real32 Lifetime;
	Vector3 LastPos, NextPos;
	bool HitTerrain;
} Particle;

/* http://www.opengl-tutorial.org/intermediate-tutorials/billboards-particles/billboards/ */
void Particle_DoRender(Vector2* size, Vector3* pos, TextureRec* rec, PackedCol col, VertexP3fT2fC4b** vertices);
void Particle_Reset(Particle* p, Vector3 pos, Vector3 velocity, Real32 lifetime);
bool Particle_PhysicsTick(Particle* p, Real32 gravity, bool throughLiquids, Real64 delta);

typedef struct RainParticle_ {
	Particle Base;
	bool Big, Tiny;
} RainParticle;

bool RainParticle_Tick(RainParticle* p, Real64 delta);
void RainParticle_Render(RainParticle* p, Real32 t, VertexP3fT2fC4b** vertices);

typedef struct TerrainParticle_ {
	Particle Base;
	TextureRec Rec;
	TextureLoc TexLoc;
	BlockID Block;
} TerrainParticle;

bool TerrainParticle_Tick(TerrainParticle* p, Real64 delta);
void TerrainParticle_Render(TerrainParticle* p, Real32 t, VertexP3fT2fC4b** vertices);

IGameComponent Particles_MakeGameComponent(void);
void Particles_Render(Real64 delta, Real32 t);
void Particles_Tick(ScheduledTask* task);
void Particles_BreakBlockEffect(Vector3I coords, BlockID oldBlock, BlockID block);
void Particles_RainSnowEffect(Vector3 pos);
#endif