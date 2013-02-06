#ifndef RSF_BYTEORDER_H
#define RSF_BYTEORDER_H

static inline uint32_t
my_bswap32(uint32_t x)
{
	return  ((x << 24) & 0xff000000 ) |
		((x <<  8) & 0x00ff0000 ) |
		((x >>  8) & 0x0000ff00 ) |
		((x >> 24) & 0x000000ff );
}

#if HAVE_DECL_HTOLE32
# define my_htole32 htole32
#else
# if IS_LITTLE_ENDIAN
#  define my_htole32(x) (x)
# else
#  define my_htole32 my_bswap32
# endif
#endif

#if HAVE_DECL_LE32TOH
# define my_le32toh le32toh
#else
# if IS_LITTLE_ENDIAN
#  define my_le32toh(x) (x)
# else
#  define my_le32toh my_bswap32
# endif
#endif

#endif /* RSF_BYTEORDER_H */
