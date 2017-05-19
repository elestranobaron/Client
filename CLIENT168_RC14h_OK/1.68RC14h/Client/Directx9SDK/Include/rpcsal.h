#pragma once

#include <specstrings.h>

#ifndef __RPCSAL_H_VERSION__
#define __RPCSAL_H_VERSION__        ( 100 )
#endif // __RPCSAL_H_VERSION__

#ifdef __REQUIRED_RPCSAL_H_VERSION__
    #if ( __RPCSAL_H_VERSION__ < __REQUIRED_RPCSAL_H_VERSION__ )
        #error incorrect <rpcsal.h> version. Use the header that matches with the MIDL compiler.
    #endif
#endif


#ifdef  __cplusplus
extern "C" {
#endif  // #ifdef __cplusplus

#if (_MSC_VER >= 1000) && !defined(__midl) && defined(_PREFAST_)


// [in]
#define __RPC__in                                   __pre __valid
#define __RPC__in_string                            __RPC__in   __pre __nullterminated
#define __RPC__in_ecount(size)                      __RPC__in __pre __elem_readableTo(size)
#define __RPC__in_ecount_full(size)                 __RPC__in_ecount(size)
#define __RPC__in_ecount_full_string(size)          __RPC__in_ecount_full(size) __pre __nullterminated
#define __RPC__in_ecount_part(size, length)         __RPC__in_ecount(length) __pre __elem_writableTo(size)
#define __RPC__in_ecount_full_opt(size)             __RPC__in_ecount_full(size) __pre __exceptthat  __maybenull
#define __RPC__in_ecount_full_opt_string(size)      __RPC__in_ecount_full_opt(size) __pre __nullterminated
#define __RPC__in_ecount_part_opt(size, length)     __RPC__in_ecount_part(size, length) __pre __exceptthat __maybenull
#define __RPC__in_xcount(size)                      __RPC__in __pre __elem_readableTo(size)
#define __RPC__in_xcount_full(size)                 __RPC__in_ecount(size)
#define __RPC__in_xcount_full_string(size)          __RPC__in_ecount_full(size) __pre __nullterminated
#define __RPC__in_xcount_part(size, length)         __RPC__in_ecount(length) __pre __elem_writableTo(size)
#define __RPC__in_xcount_full_opt(size)             __RPC__in_ecount_full(size) __pre __exceptthat  __maybenull
#define __RPC__in_xcount_full_opt_string(size)      __RPC__in_ecount_full_opt(size) __pre __nullterminated
#define __RPC__in_xcount_part_opt(size, length)     __RPC__in_ecount_part(size, length) __pre __exceptthat __maybenull


#define __RPC__deref_in                             __RPC__in __deref __notnull 
#define __RPC__deref_in_string                      __RPC__in   __pre __deref __nullterminated
#define __RPC__deref_in_opt                         __RPC__deref_in __deref __exceptthat __maybenull
#define __RPC__deref_in_opt_string                  __RPC__deref_in_opt __pre __deref __nullterminated
#define __RPC__deref_opt_in                         __RPC__in __exceptthat __maybenull 
#define __RPC__deref_opt_in_string                  __RPC__deref_opt_in __pre __deref __nullterminated 
#define __RPC__deref_opt_in_opt                     __RPC__deref_opt_in  __pre __deref __exceptthat __maybenull
#define __RPC__deref_opt_in_opt_string              __RPC__deref_opt_in_opt  __pre __deref __nullterminated
#define __RPC__deref_in_ecount(size)                __RPC__in __pre __deref __elem_readableTo(size)
#define __RPC__deref_in_ecount_part(size, length)   __RPC__deref_in_ecount(size)  __pre __deref __elem_readableTo(length)
#define __RPC__deref_in_ecount_full(size)           __RPC__deref_in_ecount_part(size, size)
#define __RPC__deref_in_ecount_full_opt(size)       __RPC__deref_in_ecount_full(size) __pre __deref __exceptthat __maybenull
#define __RPC__deref_in_ecount_full_opt_string(size) __RPC__deref_in_ecount_full_opt(size) __pre __deref __nullterminated
#define __RPC__deref_in_ecount_full_string(size)    __RPC__deref_in_ecount_full(size) __pre __deref __nullterminated
#define __RPC__deref_in_ecount_opt(size)            __RPC__deref_in_ecount(size) __pre __deref __exceptthat __maybenull
#define __RPC__deref_in_ecount_opt_string(size)     __RPC__deref_in_ecount_opt(size) __pre __deref __nullterminated
#define __RPC__deref_in_ecount_part_opt(size, length) __RPC__deref_in_ecount_opt(size) __pre __deref __elem_readableTo(length)
#define __RPC__deref_in_xcount(size)                __RPC__in __pre __deref __elem_readableTo(size)
#define __RPC__deref_in_xcount_part(size, length)   __RPC__deref_in_ecount(size)  __pre __deref __elem_readableTo(length)
#define __RPC__deref_in_xcount_full(size)           __RPC__deref_in_ecount_part(size, size)
#define __RPC__deref_in_xcount_full_opt(size)       __RPC__deref_in_ecount_full(size) __pre __deref __exceptthat __maybenull
#define __RPC__deref_in_xcount_full_opt_string(size) __RPC__deref_in_ecount_full_opt(size) __pre __deref __nullterminated
#define __RPC__deref_in_xcount_full_string(size)    __RPC__deref_in_ecount_full(size) __pre __deref __nullterminated
#define __RPC__deref_in_xcount_opt(size)            __RPC__deref_in_ecount(size) __pre __deref __exceptthat __maybenull
#define __RPC__deref_in_xcount_opt_string(size)     __RPC__deref_in_ecount_opt(size) __pre __deref __nullterminated
#define __RPC__deref_in_xcount_part_opt(size, length) __RPC__deref_in_ecount_opt(size) __pre __deref __elem_readableTo(length)

// [out]
#define __RPC__out                                  __out
#define __RPC__out_ecount(size)                     __out_ecount(size)  __post  __elem_writableTo(size)
#define __RPC__out_ecount_string(size)              __RPC__out_ecount(size) __post __nullterminated
#define __RPC__out_ecount_part(size, length)        __RPC__out_ecount(size)  __post  __elem_readableTo(length)
#define __RPC__out_ecount_full(size)                __RPC__out_ecount_part(size, size)
#define __RPC__out_ecount_full_string(size)         __RPC__out_ecount_full(size) __post  __nullterminated
#define __RPC__out_xcount(size)                     __out
#define __RPC__out_xcount_string(size)              __RPC__out __post __nullterminated
#define __RPC__out_xcount_part(size, length)        __RPC__out
#define __RPC__out_xcount_full(size)                __RPC__out
#define __RPC__out_xcount_full_string(size)         __RPC__out __post __nullterminated

// [in,out] 
#define __RPC__inout                                __inout
#define __RPC__inout_string                         __RPC__inout  __pre __nullterminated __post __nullterminated
#define __RPC__inout_ecount(size)                   __inout_ecount(size)
#define __RPC__inout_ecount_part(size, length)      __inout_ecount_part(size, length)
#define __RPC__inout_ecount_full(size)              __RPC__inout_ecount_part(size, size)
#define __RPC__inout_ecount_full_string(size)       __RPC__inout_ecount_full(size) __pre __nullterminated __post __nullterminated
#define __RPC__inout_xcount(size)                   __inout
#define __RPC__inout_xcount_part(size, length)      __inout
#define __RPC__inout_xcount_full(size)              __RPC__inout
#define __RPC__inout_xcount_full_string(size)       __RPC__inout __pre __nullterminated __post __nullterminated

// [in,unique] 
#define __RPC__in_opt                               __RPC__in __pre __exceptthat __maybenull
#define __RPC__in_opt_string                        __RPC__in_opt   __pre __nullterminated
#define __RPC__in_ecount_opt(size)                  __RPC__in_ecount(size) __pre __exceptthat __maybenull
#define __RPC__in_ecount_opt_string(size)           __RPC__in_ecount_opt(size) __pre __nullterminated
#define __RPC__in_xcount_opt(size)                  __RPC__in_ecount(size) __pre __exceptthat __maybenull
#define __RPC__in_xcount_opt_string(size)           __RPC__in_ecount_opt(size) __pre __nullterminated

// [in,out,unique] 
#define __RPC__inout_opt                            __inout_opt
#define __RPC__inout_opt_string                     __RPC__inout_opt  __pre __nullterminated
#define __RPC__inout_ecount_opt(size)               __inout_ecount_opt(size)
#define __RPC__inout_ecount_part_opt(size, length)  __inout_ecount_part_opt(size, length)
#define __RPC__inout_ecount_full_opt(size)          __RPC__inout_ecount_part_opt(size, size)
#define __RPC__inout_ecount_full_opt_string(size)   __RPC__inout_ecount_full_opt(size)  __pre __nullterminated __post __nullterminated
#define __RPC__inout_xcount_opt(size)               __inout_opt
#define __RPC__inout_xcount_part_opt(size, length)  __inout_opt
#define __RPC__inout_xcount_full_opt(size)          __RPC__inout_opt
#define __RPC__inout_xcount_full_opt_string(size)   __RPC__inout_opt __pre __nullterminated __post __nullterminated

// [out] **
#define __RPC__deref_out                            __deref_out
#define __RPC__deref_out_string                     __RPC__deref_out    __post __deref __nullterminated
// Removed "__post __deref __exceptthat __maybenull" so return values from QueryInterface and the like can be trusted without an explicit NULL check.
// This is a temporary fix until midl.exe can be rev'd to produce more accurate annotations.
#define __RPC__deref_out_opt                        __RPC__deref_out
#define __RPC__deref_out_opt_string                 __RPC__deref_out_opt  __post __deref __nullterminated __pre __deref __null
#define __RPC__deref_out_ecount(size)               __deref_out_ecount(size) __post __deref __elem_writableTo(size)
#define __RPC__deref_out_ecount_part(size, length)  __RPC__deref_out_ecount(size) __post __deref __elem_readableTo(length)
#define __RPC__deref_out_ecount_full(size)          __RPC__deref_out_ecount_part(size,size)
#define __RPC__deref_out_ecount_full_string(size)   __RPC__deref_out_ecount_full(size) __post __deref __nullterminated
#define __RPC__deref_out_xcount(size)               __deref_out __post __deref
#define __RPC__deref_out_xcount_part(size, length)  __RPC__deref_out __post __deref
#define __RPC__deref_out_xcount_full(size)          __RPC__deref_out
#define __RPC__deref_out_xcount_full_string(size)   __RPC__deref_out __post __deref __nullterminated

// [in,out] **, second pointer decoration. 
#define __RPC__deref_inout                          __deref_inout
#define __RPC__deref_inout_string                   __RPC__deref_inout __pre __deref __nullterminated __post __deref __nullterminated
#define __RPC__deref_inout_opt                      __deref_inout_opt
#define __RPC__deref_inout_opt_string               __RPC__deref_inout_opt __deref __nullterminated 
#define __RPC__deref_inout_ecount_opt(size)         __deref_inout_ecount_opt(size)
#define __RPC__deref_inout_ecount_part_opt(size, length) __deref_inout_ecount_part_opt(size , length)
#define __RPC__deref_inout_ecount_full_opt(size)    __RPC__deref_inout_ecount_part_opt(size, size)
#define __RPC__deref_inout_ecount_full(size)        __deref_inout_ecount_full(size)
#define __RPC__deref_inout_ecount_full_string(size) __RPC__deref_inout_ecount_full(size) __post __deref __nullterminated
#define __RPC__deref_inout_ecount_full_opt_string(size) __RPC__deref_inout_ecount_full_opt(size) __pre __deref __nullterminated __post __deref __nullterminated
#define __RPC__deref_inout_xcount_opt(size)         __deref_inout_opt
#define __RPC__deref_inout_xcount_part_opt(size, length) __deref_inout_opt
#define __RPC__deref_inout_xcount_full_opt(size)    __RPC__deref_inout_opt
#define __RPC__deref_inout_xcount_full(size)        __deref_inout
#define __RPC__deref_inout_xcount_full_string(size) __RPC__deref_inout __post __deref __nullterminated
#define __RPC__deref_inout_xcount_full_opt_string(size) __RPC__deref_inout_opt __pre __deref __nullterminated __post __deref __nullterminated


// #define __RPC_out_opt    out_opt is not allowed in rpc

// [in,out,unique] 
#define __RPC__deref_opt_inout                          __deref_opt_inout
#define __RPC__deref_opt_inout_ecount(size)             __deref_opt_inout_ecount(size)
#define __RPC__deref_opt_inout_string                   __RPC__deref_opt_inout __pre __deref __nullterminated __post __deref __nullterminated
#define __RPC__deref_opt_inout_ecount_part(size, length) __deref_opt_inout_ecount_part(size, length)
#define __RPC__deref_opt_inout_ecount_full(size)        __deref_opt_inout_ecount_full(size)
#define __RPC__deref_opt_inout_ecount_full_string(size)  __RPC__deref_opt_inout_ecount_full(size) __pre __deref __nullterminated __post __deref __nullterminated
#define __RPC__deref_opt_inout_xcount_part(size, length) __deref_opt_inout
#define __RPC__deref_opt_inout_xcount_full(size)        __deref_opt_inout
#define __RPC__deref_opt_inout_xcount_full_string(size)  __RPC__deref_opt_inout __pre __deref __nullterminated __post __deref __nullterminated


// We don't need to specify __pre __deref __exceptthat __maybenull : this is default behavior. While this might not hold in SAL 1.1 syntax, SAL team 
// believes it's OK. We can revisit if SAL 1.1 can survive. 
#define __RPC__deref_out_ecount_opt(size)               __RPC__out_ecount(size) __post __deref __exceptthat __maybenull __pre __deref __null 
#define __RPC__deref_out_ecount_part_opt(size, length)  __RPC__deref_out_ecount_part(size, length) __post __deref __exceptthat __maybenull __pre __deref __null
#define __RPC__deref_out_ecount_full_opt(size)          __RPC__deref_out_ecount_part_opt(size, size) __pre __deref __null
#define __RPC__deref_out_ecount_full_opt_string(size)   __RPC__deref_out_ecount_part_opt(size, size) __post __deref __nullterminated __pre __deref __null
#define __RPC__deref_out_xcount_opt(size)               __RPC__out __post __deref __exceptthat __maybenull __pre __deref __null 
#define __RPC__deref_out_xcount_part_opt(size, length)  __RPC__deref_out __post __deref __exceptthat __maybenull __pre __deref __null
#define __RPC__deref_out_xcount_full_opt(size)          __RPC__deref_out_opt __pre __deref __null
#define __RPC__deref_out_xcount_full_opt_string(size)   __RPC__deref_out_opt __post __deref __nullterminated __pre __deref __null

#define __RPC__deref_opt_inout_opt                      __deref_opt_inout_opt
#define __RPC__deref_opt_inout_opt_string               __RPC__deref_opt_inout_opt __pre __deref __nullterminated  __post __deref __nullterminated
#define __RPC__deref_opt_inout_ecount_opt(size)         __deref_opt_inout_ecount_opt(size)  
#define __RPC__deref_opt_inout_ecount_part_opt(size, length) __deref_opt_inout_ecount_part_opt(size, length)
#define __RPC__deref_opt_inout_ecount_full_opt(size)    __RPC__deref_opt_inout_ecount_part_opt(size, size)
#define __RPC__deref_opt_inout_ecount_full_opt_string(size)  __RPC__deref_opt_inout_ecount_full_opt(size) __pre __deref __nullterminated __post __deref __nullterminated
#define __RPC__deref_opt_inout_xcount_opt(size)         __deref_opt_inout_opt  
#define __RPC__deref_opt_inout_xcount_part_opt(size, length) __deref_opt_inout_opt
#define __RPC__deref_opt_inout_xcount_full_opt(size)    __RPC__deref_opt_inout_opt
#define __RPC__deref_opt_inout_xcount_full_opt_string(size)  __RPC__deref_opt_inout_opt __pre __deref __nullterminated __post __deref __nullterminated

#define __RPC_full_pointer                              __maybenull 
#define __RPC_unique_pointer                            __maybenull
#define __RPC_ref_pointer                               __notnull
#define __RPC_string                                    __nullterminated

#define __RPC__range(min,max)                           __range(min,max)
#define __RPC__in_range(min,max)                        __in_range(min,max)

#else   // not prefast

#define __RPC__range(min,max)
#define __RPC__in_range(min,max)

#define __RPC__in           
#define __RPC__in_string
#define __RPC__in_opt_string
#define __RPC__in_ecount(size) 
#define __RPC__in_ecount_full(size)
#define __RPC__in_ecount_full_string(size)
#define __RPC__in_ecount_part(size, length)
#define __RPC__in_ecount_full_opt(size)
#define __RPC__in_ecount_full_opt_string(size)
#define __RPC__inout_ecount_full_opt_string(size)
#define __RPC__in_ecount_part_opt(size, length)
#define __RPC__in_xcount(size) 
#define __RPC__in_xcount_full(size)
#define __RPC__in_xcount_full_string(size)
#define __RPC__in_xcount_part(size, length)
#define __RPC__in_xcount_full_opt(size)
#define __RPC__in_xcount_full_opt_string(size)
#define __RPC__inout_xcount_full_opt_string(size)
#define __RPC__in_xcount_part_opt(size, length)

#define __RPC__deref_in 
#define __RPC__deref_in_string
#define __RPC__deref_in_opt
#define __RPC__deref_in_opt_string
#define __RPC__deref_opt_in
#define __RPC__deref_opt_in_string
#define __RPC__deref_opt_in_opt
#define __RPC__deref_opt_in_opt_string
#define __RPC__deref_in_ecount(size) 
#define __RPC__deref_in_ecount_part(size, length) 
#define __RPC__deref_in_ecount_full(size) 
#define __RPC__deref_in_ecount_full_opt(size)
#define __RPC__deref_in_ecount_full_string(size)
#define __RPC__deref_in_ecount_full_opt_string(size)
#define __RPC__deref_in_ecount_opt(size) 
#define __RPC__deref_in_ecount_opt_string(size)
#define __RPC__deref_in_ecount_part_opt(size, length) 
#define __RPC__deref_in_xcount(size) 
#define __RPC__deref_in_xcount_part(size, length) 
#define __RPC__deref_in_xcount_full(size) 
#define __RPC__deref_in_xcount_full_opt(size)
#define __RPC__deref_in_xcount_full_string(size)
#define __RPC__deref_in_xcount_full_opt_string(size)
#define __RPC__deref_in_xcount_opt(size) 
#define __RPC__deref_in_xcount_opt_string(size)
#define __RPC__deref_in_xcount_part_opt(size, length) 

// [out]
#define __RPC__out     
#define __RPC__out_ecount(size) 
#define __RPC__out_ecount_part(size, length) 
#define __RPC__out_ecount_full(size)
#define __RPC__out_ecount_full_string(size)
#define __RPC__out_xcount(size) 
#define __RPC__out_xcount_part(size, length) 
#define __RPC__out_xcount_full(size)
#define __RPC__out_xcount_full_string(size)

// [in,out] 
#define __RPC__inout                                   
#define __RPC__inout_string
#define __RPC__opt_inout
#define __RPC__inout_ecount(size)                     
#define __RPC__inout_ecount_part(size, length)    
#define __RPC__inout_ecount_full(size)          
#define __RPC__inout_ecount_full_string(size)          
#define __RPC__inout_xcount(size)                     
#define __RPC__inout_xcount_part(size, length)    
#define __RPC__inout_xcount_full(size)          
#define __RPC__inout_xcount_full_string(size)          

// [in,unique] 
#define __RPC__in_opt       
#define __RPC__in_ecount_opt(size)   
#define __RPC__in_xcount_opt(size)   


// [in,out,unique] 
#define __RPC__inout_opt    
#define __RPC__inout_opt_string    
#define __RPC__inout_ecount_opt(size)  
#define __RPC__inout_ecount_part_opt(size, length) 
#define __RPC__inout_ecount_full_opt(size)     
#define __RPC__inout_ecount_full_string(size)
#define __RPC__inout_xcount_opt(size)  
#define __RPC__inout_xcount_part_opt(size, length) 
#define __RPC__inout_xcount_full_opt(size)     
#define __RPC__inout_xcount_full_string(size)

// [out] **
#define __RPC__deref_out   
#define __RPC__deref_out_string
#define __RPC__deref_out_opt 
#define __RPC__deref_out_opt_string
#define __RPC__deref_out_ecount(size) 
#define __RPC__deref_out_ecount_part(size, length) 
#define __RPC__deref_out_ecount_full(size)  
#define __RPC__deref_out_ecount_full_string(size)
#define __RPC__deref_out_xcount(size) 
#define __RPC__deref_out_xcount_part(size, length) 
#define __RPC__deref_out_xcount_full(size)  
#define __RPC__deref_out_xcount_full_string(size)


// [in,out] **, second pointer decoration. 
#define __RPC__deref_inout    
#define __RPC__deref_inout_string
#define __RPC__deref_inout_opt 
#define __RPC__deref_inout_opt_string
#define __RPC__deref_inout_ecount_full(size)
#define __RPC__deref_inout_ecount_full_string(size)
#define __RPC__deref_inout_ecount_opt(size) 
#define __RPC__deref_inout_ecount_part_opt(size, length) 
#define __RPC__deref_inout_ecount_full_opt(size) 
#define __RPC__deref_inout_ecount_full_opt_string(size) 
#define __RPC__deref_inout_xcount_full(size)
#define __RPC__deref_inout_xcount_full_string(size)
#define __RPC__deref_inout_xcount_opt(size) 
#define __RPC__deref_inout_xcount_part_opt(size, length) 
#define __RPC__deref_inout_xcount_full_opt(size) 
#define __RPC__deref_inout_xcount_full_opt_string(size) 

// #define __RPC_out_opt    out_opt is not allowed in rpc

// [in,out,unique] 
#define __RPC__deref_opt_inout  
#define __RPC__deref_opt_inout_string
#define __RPC__deref_opt_inout_ecount(size)     
#define __RPC__deref_opt_inout_ecount_part(size, length) 
#define __RPC__deref_opt_inout_ecount_full(size) 
#define __RPC__deref_opt_inout_ecount_full_string(size)
#define __RPC__deref_opt_inout_xcount(size)     
#define __RPC__deref_opt_inout_xcount_part(size, length) 
#define __RPC__deref_opt_inout_xcount_full(size) 
#define __RPC__deref_opt_inout_xcount_full_string(size)

#define __RPC__deref_out_ecount_opt(size) 
#define __RPC__deref_out_ecount_part_opt(size, length) 
#define __RPC__deref_out_ecount_full_opt(size) 
#define __RPC__deref_out_ecount_full_opt_string(size)
#define __RPC__deref_out_xcount_opt(size) 
#define __RPC__deref_out_xcount_part_opt(size, length) 
#define __RPC__deref_out_xcount_full_opt(size) 
#define __RPC__deref_out_xcount_full_opt_string(size)

#define __RPC__deref_opt_inout_opt      
#define __RPC__deref_opt_inout_opt_string
#define __RPC__deref_opt_inout_ecount_opt(size)   
#define __RPC__deref_opt_inout_ecount_part_opt(size, length) 
#define __RPC__deref_opt_inout_ecount_full_opt(size) 
#define __RPC__deref_opt_inout_ecount_full_opt_string(size) 
#define __RPC__deref_opt_inout_xcount_opt(size)   
#define __RPC__deref_opt_inout_xcount_part_opt(size, length) 
#define __RPC__deref_opt_inout_xcount_full_opt(size) 
#define __RPC__deref_opt_inout_xcount_full_opt_string(size) 

#define __RPC_full_pointer  
#define __RPC_unique_pointer
#define __RPC_ref_pointer
#define __RPC_string                               


#endif

#ifdef  __cplusplus
}
#endif
