#define CFSTR_VFW_FILTERLIST "Video for Windows 4 Filters"

typedef struct tagVFW_FILTERLIST{
    UINT  cFilters;                     // number of CLSIDs in aClsId
    CLSID aClsId[1];                    // ClsId of each filter
} VFW_FILTERLIST;


