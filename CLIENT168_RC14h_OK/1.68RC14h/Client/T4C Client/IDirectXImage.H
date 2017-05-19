#ifndef __DIRECTXIMAGE_H
#define __DIRECTXIMAGE_H

#include <ddraw.h>

#include "IDirectXPcx.H"

class IDirectXImage 
#ifdef __DIRECTXPCX_H
				  : public IDirectXPcx
#endif	
{
	private:
   public:
		HRESULT SetHeader(void *header);
		
		LPVOID              lpHeader;       // A pointer to the picture header
		LPDIRECTDRAWSURFACE lpImageSurface; // A pointer holding the picture
      LPBYTE              lpPal;          // A pointer holding the palette
																										
	public:
		IDirectXImage(void);          // Consturctor
		~IDirectXImage(void);         // Destructor

		HRESULT Create(int dwWidth,int dwHeight);         // Initialize
		void Release(void);				// Closing		
		HRESULT LoadImage(LPCSTR,int dwWidth,int dwHeight);    // Load the Image

		operator LPDIRECTDRAWSURFACE (void);
		LPDIRECTDRAWSURFACE ImageSurface(void);
		LPBYTE Palette(void);

};

typedef IDirectXImage FAR *LPDIRECTXIMAGE;

#endif