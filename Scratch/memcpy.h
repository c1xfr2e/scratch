
void* mem_cpy(void* dest, const void* src, size_t count)
{
    void* ret = dest;
    if (dest <= src || dest >= (char*)src + count)
    {
        while (count--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest + 1;
            src  = (char*)src + 1;
        }
    }
    else
    {
        dest = (char*)dest + count - 1;
        src = (char*)src + count - 1;
        while (count--)
        {
            *(char*)dest = *(char*)src;
            dest = (char*)dest - 1;
            src = (char*)src - 1;
        }
    }

    return ret;
}