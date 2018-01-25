#include "__cf_untitled.h"
#include "rt_logging_mmi.h"
#include "untitled_capi.h"
#include <math.h>
#include "untitled.h"
#include "untitled_private.h"
#include "untitled_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "8.8 (R2016b) 25-Aug-2016" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\untitled\\untitled_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtDW . mdhre0xjct [ 0 ] = rtP .
DiscreteTransferFcn_InitialStates ; rtDW . mdhre0xjct [ 1 ] = rtP .
DiscreteTransferFcn_InitialStates ; rtDW . mdhre0xjct [ 2 ] = rtP .
DiscreteTransferFcn_InitialStates ; rtDW . mdhre0xjct [ 3 ] = rtP .
DiscreteTransferFcn_InitialStates ; rtX . hhwnc3k50x [ 0 ] = 0.0 ; rtX .
hhwnc3k50x [ 1 ] = 0.0 ; rtX . hhwnc3k50x [ 2 ] = 0.0 ; } void MdlStart (
void ) { { void * * pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( )
; const char * errorCreatingOSigstreamManager =
rtwOSigstreamManagerCreateInstance ( rt_GetMatSigLogSelectorFileName ( ) ,
pOSigstreamManagerAddr ) ; if ( errorCreatingOSigstreamManager != ( NULL ) )
{ * pOSigstreamManagerAddr = ( NULL ) ; ssSetErrorStatus ( rtS ,
errorCreatingOSigstreamManager ) ; return ; } } if (
sdiIsUsingInlineAsyncQueues ( ) ) { { sdiSignalSourceInfoU srcInfo ;
sdiLabelU sigName = sdiGetLabelFromChars ( "control input" ) ; sdiLabelU
loggedName = sdiGetLabelFromChars ( "control input" ) ; sdiLabelU origSigName
= sdiGetLabelFromChars ( "control input" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"untitled/Controller" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ;
sdiDims sigDims ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . portIndex = 0 + 1 ; srcInfo .
signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . gvyelfai1g .
AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo
. mmi . InstanceMap . fullPath , "768ba1eb-50de-46f7-9be9-bebabd7bf970" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiSetSignalSampleTimeString ( rtDW . gvyelfai1g . AQHandles , "1e-06" ) ;
sdiSetRunStartTime ( rtDW . gvyelfai1g . AQHandles , ssGetTaskTime ( rtS , 2
) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . gvyelfai1g . AQHandles , 1
, 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . gvyelfai1g . AQHandles ,
loggedName , origSigName , propName ) ; sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; } } if
( sdiIsUsingInlineAsyncQueues ( ) ) { } else { } if (
sdiIsUsingInlineAsyncQueues ( ) ) { { sdiSignalSourceInfoU srcInfo ;
sdiLabelU sigName = sdiGetLabelFromChars ( "measured output" ) ; sdiLabelU
loggedName = sdiGetLabelFromChars ( "measured output" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "measured output" ) ; sdiLabelU propName
= sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"untitled/Plant" ) ; sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ;
sdiDims sigDims ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . portIndex = 0 + 1 ; srcInfo .
signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . nkyn11imst .
AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo
. mmi . InstanceMap . fullPath , "29b654d8-2717-48ee-9ef7-c8220ff7585f" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiSetSignalSampleTimeString ( rtDW . nkyn11imst . AQHandles , "Continuous" )
; sdiSetRunStartTime ( rtDW . nkyn11imst . AQHandles , ssGetTaskTime ( rtS ,
1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW . nkyn11imst . AQHandles ,
1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW . nkyn11imst . AQHandles ,
loggedName , origSigName , propName ) ; sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; } } if
( sdiIsUsingInlineAsyncQueues ( ) ) { } else { } if (
sdiIsUsingInlineAsyncQueues ( ) ) { { sdiSignalSourceInfoU srcInfo ;
sdiLabelU sigName = sdiGetLabelFromChars ( "error" ) ; sdiLabelU loggedName =
sdiGetLabelFromChars ( "error" ) ; sdiLabelU origSigName =
sdiGetLabelFromChars ( "error" ) ; sdiLabelU propName = sdiGetLabelFromChars
( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars ( "untitled/Sum" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
portIndex = 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID
= 0 ; rtDW . l2d0qhjoya . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT ,
& srcInfo , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"33d7c2ba-298a-487f-a15a-bbe0029d2366" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiSetSignalSampleTimeString ( rtDW .
l2d0qhjoya . AQHandles , "Continuous" ) ; sdiSetRunStartTime ( rtDW .
l2d0qhjoya . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . l2d0qhjoya . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . l2d0qhjoya . AQHandles ,
loggedName , origSigName , propName ) ; sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ; } } if
( sdiIsUsingInlineAsyncQueues ( ) ) { } else { } MdlInitialize ( ) ; { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } } void MdlOutputs ( int_T tid ) {
real_T awz5k1uzr5 ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { awz5k1uzr5 = ( (
rtP . DiscreteTransferFcn_NumCoef [ 1 ] * rtDW . mdhre0xjct [ 0 ] + rtP .
DiscreteTransferFcn_NumCoef [ 2 ] * rtDW . mdhre0xjct [ 1 ] ) + rtP .
DiscreteTransferFcn_NumCoef [ 3 ] * rtDW . mdhre0xjct [ 2 ] ) + rtP .
DiscreteTransferFcn_NumCoef [ 4 ] * rtDW . mdhre0xjct [ 3 ] ; if ( awz5k1uzr5
> rtP . Saturation_UpperSat ) { rtB . orwxcl3fbq = rtP . Saturation_UpperSat
; } else if ( awz5k1uzr5 < rtP . Saturation_LowerSat ) { rtB . orwxcl3fbq =
rtP . Saturation_LowerSat ; } else { rtB . orwxcl3fbq = awz5k1uzr5 ; } if (
ssGetLogOutput ( rtS ) ) { if ( sdiIsUsingInlineAsyncQueues ( ) ) { if ( rtDW
. gvyelfai1g . AQHandles ) { sdiWriteSignal ( rtDW . gvyelfai1g . AQHandles ,
ssGetTaskTime ( rtS , 2 ) , ( void * ) & rtB . orwxcl3fbq ) ; } } else { {
double time = ssGetTaskTime ( rtS , 2 ) ; void * pData = ( void * ) & rtB .
orwxcl3fbq ; int32_T size = 1 * sizeof ( real_T ) ; sendToAsyncQueueTgtAppSvc
( 2531150178U , time , pData , size ) ; } } } } rtB . asgpaedjpu = 0.0 ; rtB
. asgpaedjpu += rtP . TransferFcn_C [ 0 ] * rtX . hhwnc3k50x [ 0 ] ; rtB .
asgpaedjpu += rtP . TransferFcn_C [ 1 ] * rtX . hhwnc3k50x [ 1 ] ; rtB .
asgpaedjpu += rtP . TransferFcn_C [ 2 ] * rtX . hhwnc3k50x [ 2 ] ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) { if (
sdiIsUsingInlineAsyncQueues ( ) ) { if ( rtDW . nkyn11imst . AQHandles ) {
sdiWriteSignal ( rtDW . nkyn11imst . AQHandles , ssGetTaskTime ( rtS , 1 ) ,
( void * ) & rtB . asgpaedjpu ) ; } } else { { double time = ssGetTaskTime (
rtS , 1 ) ; void * pData = ( void * ) & rtB . asgpaedjpu ; int32_T size = 1 *
sizeof ( real_T ) ; sendToAsyncQueueTgtAppSvc ( 1640649507U , time , pData ,
size ) ; } } } rtDW . avbu4pf4vu = ( ssGetTaskTime ( rtS , 1 ) >= rtP .
Reference_Time ) ; if ( rtDW . avbu4pf4vu == 1 ) { rtB . nhvtbrec3d = rtP .
Reference_YFinal ; } else { rtB . nhvtbrec3d = rtP . Reference_Y0 ; } } rtB .
fxzuucao4l = rtB . nhvtbrec3d - rtB . asgpaedjpu ; if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) { if ( sdiIsUsingInlineAsyncQueues
( ) ) { if ( rtDW . l2d0qhjoya . AQHandles ) { sdiWriteSignal ( rtDW .
l2d0qhjoya . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( void * ) & rtB .
fxzuucao4l ) ; } } else { { double time = ssGetTaskTime ( rtS , 1 ) ; void *
pData = ( void * ) & rtB . fxzuucao4l ; int32_T size = 1 * sizeof ( real_T )
; sendToAsyncQueueTgtAppSvc ( 1268777426U , time , pData , size ) ; } } } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { real_T denAccum ;
if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { denAccum = ( ( ( ( rtB . fxzuucao4l -
rtP . DiscreteTransferFcn_DenCoef [ 1 ] * rtDW . mdhre0xjct [ 0 ] ) - rtP .
DiscreteTransferFcn_DenCoef [ 2 ] * rtDW . mdhre0xjct [ 1 ] ) - rtP .
DiscreteTransferFcn_DenCoef [ 3 ] * rtDW . mdhre0xjct [ 2 ] ) - rtP .
DiscreteTransferFcn_DenCoef [ 4 ] * rtDW . mdhre0xjct [ 3 ] ) / rtP .
DiscreteTransferFcn_DenCoef [ 0 ] ; rtDW . mdhre0xjct [ 3 ] = rtDW .
mdhre0xjct [ 2 ] ; rtDW . mdhre0xjct [ 2 ] = rtDW . mdhre0xjct [ 1 ] ; rtDW .
mdhre0xjct [ 1 ] = rtDW . mdhre0xjct [ 0 ] ; rtDW . mdhre0xjct [ 0 ] =
denAccum ; } UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot
* _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> hhwnc3k50x
[ 0 ] = 0.0 ; _rtXdot -> hhwnc3k50x [ 0 ] += rtP . TransferFcn_A [ 0 ] * rtX
. hhwnc3k50x [ 0 ] ; _rtXdot -> hhwnc3k50x [ 1 ] = 0.0 ; _rtXdot ->
hhwnc3k50x [ 0 ] += rtP . TransferFcn_A [ 1 ] * rtX . hhwnc3k50x [ 1 ] ;
_rtXdot -> hhwnc3k50x [ 2 ] = 0.0 ; _rtXdot -> hhwnc3k50x [ 0 ] += rtP .
TransferFcn_A [ 2 ] * rtX . hhwnc3k50x [ 2 ] ; _rtXdot -> hhwnc3k50x [ 1 ] +=
rtX . hhwnc3k50x [ 0 ] ; _rtXdot -> hhwnc3k50x [ 2 ] += rtX . hhwnc3k50x [ 1
] ; _rtXdot -> hhwnc3k50x [ 0 ] += rtB . orwxcl3fbq ; } void MdlProjection (
void ) { } void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV
* ) ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> eey5q2c1p3 = ssGetT (
rtS ) - rtP . Reference_Time ; } void MdlTerminate ( void ) { if (
sdiIsUsingInlineAsyncQueues ( ) ) { if ( rtDW . gvyelfai1g . AQHandles ) {
sdiTerminateStreaming ( & rtDW . gvyelfai1g . AQHandles ) ; } } if (
sdiIsUsingInlineAsyncQueues ( ) ) { if ( rtDW . nkyn11imst . AQHandles ) {
sdiTerminateStreaming ( & rtDW . nkyn11imst . AQHandles ) ; } } if (
sdiIsUsingInlineAsyncQueues ( ) ) { if ( rtDW . l2d0qhjoya . AQHandles ) {
sdiTerminateStreaming ( & rtDW . l2d0qhjoya . AQHandles ) ; } }
rtwOSigstreamManagerSaveDatasetsToMatFile ( rt_GetOSigstreamManager ( ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwOSigstreamManagerDestroyInstance
( rt_GetOSigstreamManager ( ) ) ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 3 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 3 ) ; ssSetNumBlocks ( rtS , 8 ) ;
ssSetNumBlockIO ( rtS , 4 ) ; ssSetNumBlockParams ( rtS , 22 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , 1.0E-6 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 1608993079U ) ; ssSetChecksumVal ( rtS ,
1 , 1720908219U ) ; ssSetChecksumVal ( rtS , 2 , 1403314151U ) ;
ssSetChecksumVal ( rtS , 3 , 3867020258U ) ; } SimStruct *
raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo ; ( void )
memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( (
char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr (
rtS , & mdlInfo ) ; { static time_T mdlPeriod [ NSAMPLE_TIMES ] ; static
time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T mdlTaskTimes [
NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ; static int_T
mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T mdlTNextWasAdjustedPtr [
NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES *
NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; {
int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ;
mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ;
mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] )
; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ;
ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr
( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS ,
& mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { real_T * x = ( real_T * )
& rtX ; ssSetContStates ( rtS , x ) ; ( void ) memset ( ( void * ) x , 0 ,
sizeof ( X ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS
, dwork ) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; }
untitled_InitializeDataMapInfo ( rtS ) ; ssSetIsRapidAcceleratorActive ( rtS
, true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "untitled" ) ; ssSetPath
( rtS , "untitled" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 1.0 )
; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 1000 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo (
rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 3 ] ; static
real_T absTol [ 3 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 } ; static uint8_T
absTolControl [ 3 ] = { 0U , 0U , 0U } ; static uint8_T zcAttributes [ 1 ] =
{ ( ZC_EVENT_ALL_UP ) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [
1 ] = { { 1 * sizeof ( real_T ) , ( char * ) ( & rtB . orwxcl3fbq ) , ( NULL
) } } ; ssSetSolverRelTol ( rtS , 0.0001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 1.0E-6 ) ;
ssSetSolverMaxOrder ( rtS , 5 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 1 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode15s" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 1 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 1 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1608993079U ) ; ssSetChecksumVal ( rtS , 1 ,
1720908219U ) ; ssSetChecksumVal ( rtS , 2 , 1403314151U ) ; ssSetChecksumVal
( rtS , 3 , 3867020258U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 1 ] ; ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo
) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; } const int_T gblParameterTuningTid = - 1 ; void
MdlOutputsParameterSampleTime ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
