#ifndef OBJECT_ANI_H
#define OBJECT_ANI_H 1

extern StandardLimb gRoofManRootLimb;
extern StandardLimb gRoofManLeftThighLimb;
extern StandardLimb gRoofManLeftLegLimb;
extern StandardLimb gRoofManLeftFootLimb;
extern StandardLimb gRoofManRightThighLimb;
extern StandardLimb gRoofManRightLegLimb;
extern StandardLimb gRoofManRightFootLimb;
extern StandardLimb gRoofManTorsoLimb;
extern StandardLimb gRoofManLeftUpperArmLimb;
extern StandardLimb gRoofManLeftForearmLimb;
extern StandardLimb gRoofManLeftHandLimb;
extern StandardLimb gRoofManRightUpperArmLimb;
extern StandardLimb gRoofManRightForearmLimb;
extern StandardLimb gRoofManRightHandLimb;
extern StandardLimb gRoofManHeadLimb;
extern void* gRoofManSkelLimbs[];
extern FlexSkeletonHeader gRoofManSkel;
extern u64 gRoofMan1TLUT[];
extern u64 gRoofManEyeOpenTex[];
extern u64 gRoofManHandBackTex[];
extern u64 gRoofManForearmGradientTex[];
extern u64 gRoofManThighGradientTex[];
extern u64 gRoofManSandalBuckleTex[];
extern u64 gRoofManTrouserPatternTex[];
extern u64 gRoofMan2TLUT[];
extern u64 object_aniTex_0011D8[];
extern u64 gRoofManSkinGradientTex[];
extern u64 gRoofManEarTex[];
extern u64 gRoofManHairTex[];
extern u64 gRoofManEyeHalfTex[];
extern u64 gRoofManEyeClosedTex[];
extern Vtx object_aniVtx_002518[];
extern Gfx gRoofManHeadDL[];
extern Vtx object_aniVtx_002FA8[];
extern Gfx gRoofManRightHandDL[];
extern Gfx gRoofManRightForearmDL[];
extern Gfx gRoofManRightUpperArmDL[];
extern Gfx gRoofManLeftHandDL[];
extern Gfx gRoofManLeftForearmDL[];
extern Gfx gRoofManLeftUpperArmDL[];
extern Gfx gRoofManTorsoDL[];
extern Gfx gRoofManRightFootDL[];
extern Gfx gRoofManRightLegDL[];
extern Gfx gRoofManRightThighDL[];
extern Gfx gRoofManLeftFootDL[];
extern Gfx gRoofManLeftLegDL[];
extern Gfx gRoofManLeftThighDL[];
extern Gfx gRoofManWaistDL[];
extern s16 sRoofManKnockbackAnimFrameData[];
extern JointIndex sRoofManKnockbackAnimJointIndices[];
extern AnimationHeader gRoofManKnockbackAnim;
extern s16 sRoofManGettingUpAfterKnockbackAnimFrameData[];
extern JointIndex sRoofManGettingUpAfterKnockbackAnimJointIndices[];
extern AnimationHeader gRoofManGettingUpAfterKnockbackAnim;
extern s16 sRoofManIdleAnimFrameData[];
extern JointIndex sRoofManIdleAnimJointIndices[];
extern AnimationHeader gRoofManIdleAnim;

#endif
