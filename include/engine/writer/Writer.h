/*
 * SingleBP.h
 *
 *  Created on: Dec 16, 2016
 *      Author: wfg
 */

#ifndef WRITER_H_
#define WRITER_H_

#include "core/Engine.h"
#include "format/BP1Writer.h"
#include "capsule/Heap.h"


namespace adios
{


class Writer : public Engine
{

public:

    /**
     * Constructor for Writer writes in BP format into a single heap capsule, manages several transports
     * @param name unique name given to the engine
     * @param accessMode
     * @param mpiComm
     * @param method
     * @param debugMode
     */
    Writer( const std::string name, const std::string accessMode, MPI_Comm mpiComm,
            const Method& method, const bool debugMode = false, const unsigned int cores = 1 );

    ~Writer( );

    void Write( Group& group, const std::string variableName, const char* values );
    void Write( Group& group, const std::string variableName, const unsigned char* values );
    void Write( Group& group, const std::string variableName, const short* values );
    void Write( Group& group, const std::string variableName, const unsigned short* values );
    void Write( Group& group, const std::string variableName, const int* values );
    void Write( Group& group, const std::string variableName, const unsigned int* values );
    void Write( Group& group, const std::string variableName, const long int* values );
    void Write( Group& group, const std::string variableName, const unsigned long int* values );
    void Write( Group& group, const std::string variableName, const long long int* values );
    void Write( Group& group, const std::string variableName, const unsigned long long int* values );
    void Write( Group& group, const std::string variableName, const float* values );
    void Write( Group& group, const std::string variableName, const double* values );
    void Write( Group& group, const std::string variableName, const long double* values );

    void Write( const std::string variableName, const char* values );
    void Write( const std::string variableName, const unsigned char* values );
    void Write( const std::string variableName, const short* values );
    void Write( const std::string variableName, const unsigned short* values );
    void Write( const std::string variableName, const int* values );
    void Write( const std::string variableName, const unsigned int* values );
    void Write( const std::string variableName, const long int* values );
    void Write( const std::string variableName, const unsigned long int* values );
    void Write( const std::string variableName, const long long int* values );
    void Write( const std::string variableName, const unsigned long long int* values );
    void Write( const std::string variableName, const float* values );
    void Write( const std::string variableName, const double* values );
    void Write( const std::string variableName, const long double* values );

    void Close( const int transportIndex = -1 );

private:

    Heap m_Buffer; ///< heap capsule
    float m_GrowthFactor = 1.5;
    std::size_t m_MaxBufferSize;
    format::BP1Writer m_BP1Writer; ///< format object will provide the required BP functionality to be applied on m_Buffer and m_Transports

    void Init( );
    void InitTransports( );

};


} //end namespace adios


#endif /* WRITER_H_ */
