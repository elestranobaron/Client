extern void wav_end(struct AUDIO_HEADER *header);
extern void wav_begin(void);

#ifdef FORMATS
void wav_end(struct AUDIO_HEADER *header);
void wav_begin(void);
#endif /* FORMATS */
