#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Caja.o \
	${OBJECTDIR}/Carreta.o \
	${OBJECTDIR}/Cliente.o \
	${OBJECTDIR}/ColaClientes.o \
	${OBJECTDIR}/ListaCajas.o \
	${OBJECTDIR}/ListaClientes.o \
	${OBJECTDIR}/NodoColaClientes.o \
	${OBJECTDIR}/NodoListaCajas.o \
	${OBJECTDIR}/NodoListaCompra.o \
	${OBJECTDIR}/NodoPilaCarretas.o \
	${OBJECTDIR}/PilaCarretas.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicaestructurasdedatos_vacacionesjunio2019.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicaestructurasdedatos_vacacionesjunio2019.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/practicaestructurasdedatos_vacacionesjunio2019 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Caja.o: Caja.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Caja.o Caja.cpp

${OBJECTDIR}/Carreta.o: Carreta.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Carreta.o Carreta.cpp

${OBJECTDIR}/Cliente.o: Cliente.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Cliente.o Cliente.cpp

${OBJECTDIR}/ColaClientes.o: ColaClientes.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ColaClientes.o ColaClientes.cpp

${OBJECTDIR}/ListaCajas.o: ListaCajas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaCajas.o ListaCajas.cpp

${OBJECTDIR}/ListaClientes.o: ListaClientes.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ListaClientes.o ListaClientes.cpp

${OBJECTDIR}/NodoColaClientes.o: NodoColaClientes.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NodoColaClientes.o NodoColaClientes.cpp

${OBJECTDIR}/NodoListaCajas.o: NodoListaCajas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NodoListaCajas.o NodoListaCajas.cpp

${OBJECTDIR}/NodoListaCompra.o: NodoListaCompra.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NodoListaCompra.o NodoListaCompra.cpp

${OBJECTDIR}/NodoPilaCarretas.o: NodoPilaCarretas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/NodoPilaCarretas.o NodoPilaCarretas.cpp

${OBJECTDIR}/PilaCarretas.o: PilaCarretas.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/PilaCarretas.o PilaCarretas.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
