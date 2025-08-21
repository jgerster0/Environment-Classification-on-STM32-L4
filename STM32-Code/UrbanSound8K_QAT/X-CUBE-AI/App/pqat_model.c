/**
  ******************************************************************************
  * @file    pqat_model.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2025-05-07T02:55:44+0200
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "pqat_model.h"
#include "pqat_model_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_pqat_model
 
#undef AI_PQAT_MODEL_MODEL_SIGNATURE
#define AI_PQAT_MODEL_MODEL_SIGNATURE     "0x5a118e249a082f27dedca248bc3f8d4a"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "2025-05-07T02:55:44+0200"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_PQAT_MODEL_N_BATCHES
#define AI_PQAT_MODEL_N_BATCHES         (1)

static ai_ptr g_pqat_model_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_pqat_model_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_input_80_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 480, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1200, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 448, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_pad_before_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  gemm_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  nl_9_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 10, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  gemm_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 640, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  gemm_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 10, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6080, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 320, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7040, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8064, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 192, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  gemm_8_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 64, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  nl_9_scratch0_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 124, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.516611635684967f),
    AI_PACK_INTQ_ZP(-127)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.516611635684967f),
    AI_PACK_INTQ_ZP(-127)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_scratch2_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.516611635684967f),
    AI_PACK_INTQ_ZP(-127)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0038310156669467688f, 0.0039696539752185345f, 0.005528994370251894f, 0.003065171418711543f, 0.003233813215047121f, 0.004990537650883198f, 0.003972826991230249f, 0.00360984168946743f, 0.004244946409016848f, 0.0033141544554382563f, 0.00413472717627883f, 0.004795570392161608f, 0.003842212725430727f, 0.006129878107458353f, 0.0027621884364634752f, 0.004321076441556215f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.22849108278751373f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.516611635684967f),
    AI_PACK_INTQ_ZP(-127)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.22849108278751373f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_scratch2_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.22849108278751373f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002290755044668913f, 0.0021591312251985073f, 0.002554647857323289f, 0.0022005923092365265f, 0.0021103760227560997f, 0.001627038698643446f, 0.0028732302598655224f, 0.002705458551645279f, 0.002173518529161811f, 0.0022418454755097628f, 0.0025425876956433058f, 0.002540143206715584f, 0.003761387662962079f, 0.002640600549057126f, 0.0022052668500691652f, 0.003104102797806263f, 0.0020545891020447016f, 0.0024810086470097303f, 0.0023774635046720505f, 0.0027067656628787518f, 0.0022268739994615316f, 0.0019337923731654882f, 0.002331717172637582f, 0.002082656603306532f, 0.002382549224421382f, 0.002719341078773141f, 0.002009984338656068f, 0.0030179040040820837f, 0.0021787728182971478f, 0.0025032765697687864f, 0.0019113562302663922f, 0.002701574470847845f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05116935074329376f),
    AI_PACK_INTQ_ZP(-115)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.22849108278751373f),
    AI_PACK_INTQ_ZP(-125)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05116935074329376f),
    AI_PACK_INTQ_ZP(-115)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_scratch2_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05116935074329376f),
    AI_PACK_INTQ_ZP(-115)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0015610508853569627f, 0.0020218302961438894f, 0.001684738090261817f, 0.0017354284645989537f, 0.0014247067738324404f, 0.002474916400387883f, 0.0014599091373383999f, 0.0016381882596760988f, 0.0018192983698099852f, 0.002133256522938609f, 0.0019201565301045775f, 0.0020493848714977503f, 0.001759157981723547f, 0.002040823921561241f, 0.0022192271426320076f, 3.937008052901092e-09f, 0.001630605198442936f, 0.001632148865610361f, 0.0018592230044305325f, 0.0015506540657952428f, 0.002088352106511593f, 0.0017235605046153069f, 0.0015376891242340207f, 0.0017881171079352498f, 0.002442884026095271f, 0.0019221456022933125f, 0.0014846421545371413f, 0.001533282338641584f, 0.0016392169054597616f, 0.0020036818459630013f, 0.0024722497910261154f, 0.001489028800278902f, 0.001638877671211958f, 0.002122654113918543f, 0.0017345170490443707f, 0.00145056564360857f, 0.001899714581668377f, 0.0015579633181914687f, 0.001481513725593686f, 0.002329489914700389f, 0.0017965538427233696f, 0.001794254407286644f, 0.002003694185987115f, 0.0018358457600697875f, 0.00175057677552104f, 0.0020035896450281143f, 3.937008052901092e-09f, 0.0013895448064431548f, 0.0020556384697556496f, 0.0016274978406727314f, 0.001735011232085526f, 0.0021362381521612406f, 0.0017103726277127862f, 0.0019544444512575865f, 0.0014030564343556762f, 0.001534957205876708f, 0.0017485017888247967f, 0.0019470993429422379f, 0.0017431548330932856f, 0.0014292349806055427f, 0.001241876743733883f, 0.001681540859863162f, 0.0022352368105202913f, 0.0022108876146376133f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.031057074666023254f),
    AI_PACK_INTQ_ZP(-107)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_pad_before_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05116935074329376f),
    AI_PACK_INTQ_ZP(-115)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04089878872036934f),
    AI_PACK_INTQ_ZP(-112)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_scratch2_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04089878872036934f),
    AI_PACK_INTQ_ZP(-112)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0016809719381853938f, 0.001608758931979537f, 0.0013971718726679683f, 0.001766706700436771f, 0.0016277475515380502f, 0.0017641405574977398f, 0.0017676572315394878f, 0.0015840829582884908f, 0.0015734225744381547f, 0.0016583555843681097f, 0.0019740548450499773f, 0.0016788721550256014f, 0.0012921611778438091f, 0.0016978716012090445f, 0.0017091454938054085f, 0.0018943505128845572f, 0.0019355769036337733f, 0.0013885890366509557f, 0.0013967049308121204f, 0.0019944445230066776f, 0.0015006479807198048f, 0.0013766232877969742f, 0.0017724677454680204f, 0.0017721590120345354f, 0.0020338536705821753f, 0.001939237117767334f, 0.0012856113025918603f, 0.0018543716287240386f, 0.0025141846854239702f, 0.0018958552973344922f, 0.00159917410928756f, 0.0015094992704689503f, 0.0020320946350693703f, 0.0014418769860640168f, 0.0017717689042910933f, 0.001461540348827839f, 0.0012555685825645924f, 0.0011070501059293747f, 0.0015982076292857528f, 0.0019183721160516143f, 0.001851957174949348f, 0.0014440326485782862f, 0.0018755656201392412f, 0.0018480512080714107f, 0.001786842942237854f, 0.00136042688973248f, 0.001327209989540279f, 0.00196399400010705f, 0.0018263735109940171f, 0.0020112197380512953f, 0.0014891145983710885f, 0.0016281255520880222f, 0.001476465491577983f, 0.001637882785871625f, 0.0015131302643567324f, 0.0015646726824343204f, 0.0016749183414503932f, 0.0018999945605173707f, 0.0015362194972112775f, 0.0019543180242180824f, 0.0017711811233311892f, 0.001812945120036602f, 0.0016815530834719539f, 0.0017429313156753778f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_8_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.23314324021339417f),
    AI_PACK_INTQ_ZP(43)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(gemm_8_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012785786762833595f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_9_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_input_80_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8295904994010925f),
    AI_PACK_INTQ_ZP(83)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_bias, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_0_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 5, 15), AI_STRIDE_INIT(4, 1, 1, 16, 80),
  1, &conv2d_0_output_array, &conv2d_0_output_array_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch0, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_0_scratch0_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch1, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 2), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &conv2d_0_scratch1_array, &conv2d_0_scratch1_array_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch2, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 2), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &conv2d_0_scratch2_array, &conv2d_0_scratch2_array_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_weights, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 4, 2, 16), AI_STRIDE_INIT(4, 1, 1, 16, 64),
  1, &conv2d_0_weights_array, &conv2d_0_weights_array_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_2_bias_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 2, 7), AI_STRIDE_INIT(4, 1, 1, 32, 64),
  1, &conv2d_2_output_array, &conv2d_2_output_array_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_pad_before_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 8, 16), AI_STRIDE_INIT(4, 1, 1, 16, 128),
  1, &conv2d_2_pad_before_output_array, &conv2d_2_pad_before_output_array_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 6080, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6080, 6080),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch1, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 5, 2), AI_STRIDE_INIT(4, 1, 1, 32, 160),
  1, &conv2d_2_scratch1_array, &conv2d_2_scratch1_array_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch2, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 5, 2), AI_STRIDE_INIT(4, 1, 1, 32, 160),
  1, &conv2d_2_scratch2_array, &conv2d_2_scratch2_array_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 16, 4, 2, 32), AI_STRIDE_INIT(4, 1, 16, 512, 2048),
  1, &conv2d_2_weights_array, &conv2d_2_weights_array_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_4_bias_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 3), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &conv2d_4_output_array, &conv2d_4_output_array_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_pad_before_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 5, 8), AI_STRIDE_INIT(4, 1, 1, 32, 160),
  1, &conv2d_4_pad_before_output_array, &conv2d_4_pad_before_output_array_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 7040, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7040, 7040),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch1, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 1, 1, 64, 128),
  1, &conv2d_4_scratch1_array, &conv2d_4_scratch1_array_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch2, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 2, 2), AI_STRIDE_INIT(4, 1, 1, 64, 128),
  1, &conv2d_4_scratch2_array, &conv2d_4_scratch2_array_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 32, 4, 2, 64), AI_STRIDE_INIT(4, 1, 32, 2048, 8192),
  1, &conv2d_4_weights_array, &conv2d_4_weights_array_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_6_bias_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &conv2d_6_output_array, &conv2d_6_output_array_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_pad_before_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 4, 4), AI_STRIDE_INIT(4, 1, 1, 64, 256),
  1, &conv2d_6_pad_before_output_array, &conv2d_6_pad_before_output_array_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 8064, 1, 1), AI_STRIDE_INIT(4, 1, 1, 8064, 8064),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch1, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 3), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &conv2d_6_scratch1_array, &conv2d_6_scratch1_array_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch2, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 3), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &conv2d_6_scratch2_array, &conv2d_6_scratch2_array_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 64, 4, 2, 64), AI_STRIDE_INIT(4, 1, 64, 4096, 16384),
  1, &conv2d_6_weights_array, &conv2d_6_weights_array_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  gemm_8_bias, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &gemm_8_bias_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  gemm_8_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10, 10),
  1, &gemm_8_output_array, &gemm_8_output_array_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  gemm_8_scratch0, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 2, 2, 128, 128),
  1, &gemm_8_scratch0_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  gemm_8_weights, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 64, 10, 1, 1), AI_STRIDE_INIT(4, 1, 64, 640, 640),
  1, &gemm_8_weights_array, &gemm_8_weights_array_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  nl_9_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10, 10),
  1, &nl_9_output_array, &nl_9_output_array_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  nl_9_scratch0, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 124, 1, 1), AI_STRIDE_INIT(4, 4, 4, 496, 496),
  1, &nl_9_scratch0_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_input_80_output, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 16, 30), AI_STRIDE_INIT(4, 1, 1, 1, 16),
  1, &serving_default_input_80_output_array, &serving_default_input_80_output_array_intq)



/**  Layer declarations section  **********************************************/



AI_STATIC_CONST ai_i32 nl_9_nl_params_data[] = { 2002685184, 24, -124 };
AI_ARRAY_OBJ_DECLARE(
    nl_9_nl_params, AI_ARRAY_FORMAT_S32,
    nl_9_nl_params_data, nl_9_nl_params_data, 3, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_9_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  nl_9_layer, 9,
  SM_TYPE, 0x0, NULL,
  sm, forward_sm_integer,
  &nl_9_chain,
  NULL, &nl_9_layer, AI_STATIC, 
  .nl_params = &nl_9_nl_params, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_8_weights, &gemm_8_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_8_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  gemm_8_layer, 8,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &gemm_8_chain,
  NULL, &nl_9_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i8 conv2d_6_nl_params_data[] = { -112 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_6_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_6_nl_params_data, conv2d_6_nl_params_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_scratch0, &conv2d_6_scratch1, &conv2d_6_scratch2)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 7,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_deep_sssa8_ch_nl_pool,
  &conv2d_6_chain,
  NULL, &gemm_8_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_6_nl_params, 
  .nl_func = AI_HANDLE_PTR(nl_func_relu_array_integer), 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(1, 3), 
  .pool_stride = AI_SHAPE_2D_INIT(1, 3), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = AI_HANDLE_PTR(pool_func_ap_array_integer_INT8), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_6_pad_before_value_data[] = { -115 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_6_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_6_pad_before_value_data, conv2d_6_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_pad_before_layer, 6,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_6_pad_before_chain,
  NULL, &conv2d_6_layer, AI_STATIC, 
  .value = &conv2d_6_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 1, 1, 2), 
)


AI_STATIC_CONST ai_i8 conv2d_4_nl_params_data[] = { -115 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_4_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_4_nl_params_data, conv2d_4_nl_params_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_scratch0, &conv2d_4_scratch1, &conv2d_4_scratch2)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 5,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_deep_sssa8_ch_nl_pool,
  &conv2d_4_chain,
  NULL, &conv2d_6_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_4_nl_params, 
  .nl_func = AI_HANDLE_PTR(nl_func_relu_array_integer), 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = AI_HANDLE_PTR(pool_func_mp_array_integer_INT8), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_4_pad_before_value_data[] = { -125 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_4_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_4_pad_before_value_data, conv2d_4_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_pad_before_layer, 4,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_4_pad_before_chain,
  NULL, &conv2d_4_layer, AI_STATIC, 
  .value = &conv2d_4_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 1, 1, 2), 
)


AI_STATIC_CONST ai_i8 conv2d_2_nl_params_data[] = { -125 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_2_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_2_nl_params_data, conv2d_2_nl_params_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_pad_before_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_scratch0, &conv2d_2_scratch1, &conv2d_2_scratch2)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 3,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_deep_sssa8_ch_nl_pool,
  &conv2d_2_chain,
  NULL, &conv2d_4_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_2_nl_params, 
  .nl_func = AI_HANDLE_PTR(nl_func_relu_array_integer), 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = AI_HANDLE_PTR(pool_func_mp_array_integer_INT8), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_i8 conv2d_2_pad_before_value_data[] = { -127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_2_pad_before_value, AI_ARRAY_FORMAT_S8,
    conv2d_2_pad_before_value_data, conv2d_2_pad_before_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_pad_before_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_pad_before_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_pad_before_layer, 2,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &conv2d_2_pad_before_chain,
  NULL, &conv2d_2_layer, AI_STATIC, 
  .value = &conv2d_2_pad_before_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 0, 1, 1, 2), 
)


AI_STATIC_CONST ai_i8 conv2d_0_nl_params_data[] = { -127 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_0_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_0_nl_params_data, conv2d_0_nl_params_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_input_80_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_0_weights, &conv2d_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_0_scratch0, &conv2d_0_scratch1, &conv2d_0_scratch2)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_0_layer, 1,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_sssa8_ch_nl_pool,
  &conv2d_0_chain,
  NULL, &conv2d_2_pad_before_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_0_nl_params, 
  .nl_func = AI_HANDLE_PTR(nl_func_relu_array_integer), 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 1, 1, 2), 
  .pool_size = AI_SHAPE_2D_INIT(3, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(3, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = AI_HANDLE_PTR(pool_func_mp_array_integer_INT8), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_SAME, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 54760, 1, 1),
    54760, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 9344, 1, 1),
    9344, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PQAT_MODEL_IN_NUM, &serving_default_input_80_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PQAT_MODEL_OUT_NUM, &nl_9_output),
  &conv2d_0_layer, 0x4becdefa, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 54760, 1, 1),
      54760, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 9344, 1, 1),
      9344, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PQAT_MODEL_IN_NUM, &serving_default_input_80_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_PQAT_MODEL_OUT_NUM, &nl_9_output),
  &conv2d_0_layer, 0x4becdefa, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool pqat_model_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_pqat_model_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_input_80_output_array.data = AI_PTR(g_pqat_model_activations_map[0] + 1632);
    serving_default_input_80_output_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 1632);
    conv2d_0_scratch0_array.data = AI_PTR(g_pqat_model_activations_map[0] + 2112);
    conv2d_0_scratch0_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 2112);
    conv2d_0_scratch1_array.data = AI_PTR(g_pqat_model_activations_map[0] + 1120);
    conv2d_0_scratch1_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 1120);
    conv2d_0_scratch2_array.data = AI_PTR(g_pqat_model_activations_map[0] + 608);
    conv2d_0_scratch2_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 608);
    conv2d_0_output_array.data = AI_PTR(g_pqat_model_activations_map[0] + 2624);
    conv2d_0_output_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 2624);
    conv2d_2_pad_before_output_array.data = AI_PTR(g_pqat_model_activations_map[0] + 576);
    conv2d_2_pad_before_output_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 576);
    conv2d_2_scratch0_array.data = AI_PTR(g_pqat_model_activations_map[0] + 2624);
    conv2d_2_scratch0_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 2624);
    conv2d_2_scratch1_array.data = AI_PTR(g_pqat_model_activations_map[0] + 8704);
    conv2d_2_scratch1_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 8704);
    conv2d_2_scratch2_array.data = AI_PTR(g_pqat_model_activations_map[0] + 8704);
    conv2d_2_scratch2_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 8704);
    conv2d_2_output_array.data = AI_PTR(g_pqat_model_activations_map[0] + 512);
    conv2d_2_output_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 512);
    conv2d_4_pad_before_output_array.data = AI_PTR(g_pqat_model_activations_map[0] + 7744);
    conv2d_4_pad_before_output_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 7744);
    conv2d_4_scratch0_array.data = AI_PTR(g_pqat_model_activations_map[0] + 512);
    conv2d_4_scratch0_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 512);
    conv2d_4_scratch1_array.data = AI_PTR(g_pqat_model_activations_map[0] + 9024);
    conv2d_4_scratch1_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 9024);
    conv2d_4_scratch2_array.data = AI_PTR(g_pqat_model_activations_map[0] + 9024);
    conv2d_4_scratch2_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 9024);
    conv2d_4_output_array.data = AI_PTR(g_pqat_model_activations_map[0] + 320);
    conv2d_4_output_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 320);
    conv2d_6_pad_before_output_array.data = AI_PTR(g_pqat_model_activations_map[0] + 8256);
    conv2d_6_pad_before_output_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 8256);
    conv2d_6_scratch0_array.data = AI_PTR(g_pqat_model_activations_map[0] + 192);
    conv2d_6_scratch0_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 192);
    conv2d_6_scratch1_array.data = AI_PTR(g_pqat_model_activations_map[0] + 0);
    conv2d_6_scratch1_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 0);
    conv2d_6_scratch2_array.data = AI_PTR(g_pqat_model_activations_map[0] + 0);
    conv2d_6_scratch2_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 0);
    conv2d_6_output_array.data = AI_PTR(g_pqat_model_activations_map[0] + 9280);
    conv2d_6_output_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 9280);
    gemm_8_scratch0_array.data = AI_PTR(g_pqat_model_activations_map[0] + 0);
    gemm_8_scratch0_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 0);
    gemm_8_output_array.data = AI_PTR(g_pqat_model_activations_map[0] + 128);
    gemm_8_output_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 128);
    nl_9_scratch0_array.data = AI_PTR(g_pqat_model_activations_map[0] + 140);
    nl_9_scratch0_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 140);
    nl_9_output_array.data = AI_PTR(g_pqat_model_activations_map[0] + 0);
    nl_9_output_array.data_start = AI_PTR(g_pqat_model_activations_map[0] + 0);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool pqat_model_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_pqat_model_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    conv2d_0_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_weights_array.data = AI_PTR(g_pqat_model_weights_map[0] + 0);
    conv2d_0_weights_array.data_start = AI_PTR(g_pqat_model_weights_map[0] + 0);
    conv2d_0_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_bias_array.data = AI_PTR(g_pqat_model_weights_map[0] + 128);
    conv2d_0_bias_array.data_start = AI_PTR(g_pqat_model_weights_map[0] + 128);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(g_pqat_model_weights_map[0] + 192);
    conv2d_2_weights_array.data_start = AI_PTR(g_pqat_model_weights_map[0] + 192);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(g_pqat_model_weights_map[0] + 4288);
    conv2d_2_bias_array.data_start = AI_PTR(g_pqat_model_weights_map[0] + 4288);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(g_pqat_model_weights_map[0] + 4416);
    conv2d_4_weights_array.data_start = AI_PTR(g_pqat_model_weights_map[0] + 4416);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(g_pqat_model_weights_map[0] + 20800);
    conv2d_4_bias_array.data_start = AI_PTR(g_pqat_model_weights_map[0] + 20800);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(g_pqat_model_weights_map[0] + 21056);
    conv2d_6_weights_array.data_start = AI_PTR(g_pqat_model_weights_map[0] + 21056);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(g_pqat_model_weights_map[0] + 53824);
    conv2d_6_bias_array.data_start = AI_PTR(g_pqat_model_weights_map[0] + 53824);
    gemm_8_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_8_weights_array.data = AI_PTR(g_pqat_model_weights_map[0] + 54080);
    gemm_8_weights_array.data_start = AI_PTR(g_pqat_model_weights_map[0] + 54080);
    gemm_8_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_8_bias_array.data = AI_PTR(g_pqat_model_weights_map[0] + 54720);
    gemm_8_bias_array.data_start = AI_PTR(g_pqat_model_weights_map[0] + 54720);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_pqat_model_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_PQAT_MODEL_MODEL_NAME,
      .model_signature   = AI_PQAT_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 718416,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x4becdefa,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_pqat_model_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_PQAT_MODEL_MODEL_NAME,
      .model_signature   = AI_PQAT_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 718416,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x4becdefa,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_pqat_model_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_pqat_model_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_pqat_model_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_pqat_model_create(network, AI_PQAT_MODEL_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_pqat_model_data_params_get(&params) != true) {
    err = ai_pqat_model_get_error(*network);
    return err;
  }
#if defined(AI_PQAT_MODEL_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_PQAT_MODEL_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_pqat_model_init(*network, &params) != true) {
    err = ai_pqat_model_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_pqat_model_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_pqat_model_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_pqat_model_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_pqat_model_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= pqat_model_configure_weights(net_ctx, params);
  ok &= pqat_model_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_pqat_model_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_pqat_model_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_PQAT_MODEL_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

