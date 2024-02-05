// origin: https://github.com/green-anger/MemoryPool/tree/master
// Licence MIT
// adapted by Dominique Kunz for universal use on stack, data segment and heap

#include <cstdint>

template<typename T, size_t NumCells>
class MemPool
{
public:
    //MemPool();
    MemPool();
    ~MemPool();
    void CreatePool( uint32_t num_cells );
    void DestroyPool();
    T* Allocate();
    void Deallocate( void* p );

private:
    uint8_t* AddrFromIndex( uint32_t i ) const;
    uint32_t IndexFromAddr( const uint8_t* p ) const;

    const uint32_t cell_size_ = sizeof( T );
    uint32_t num_cells_ = NumCells;
    uint32_t num_free_cells_ = NumCells;
    uint32_t num_init_ = 0;
    uint8_t mempool_buffer[sizeof(T)*NumCells];//adaption
    uint8_t* mem_beg_ = mempool_buffer;
    uint8_t* next_ = mem_beg_;
};

template<typename T, size_t NumCells>
MemPool<T, NumCells>::MemPool()
{
    static_assert( sizeof( uint32_t ) <= sizeof( T ), "sizeof( T ) must be equal or greater than sizeof( uint32_t )" );
}


template<typename T, size_t NumCells>
 MemPool<T, NumCells>::~MemPool()
{

}


template<typename T, size_t NumCells>
void MemPool<T, NumCells>::CreatePool( uint32_t num_cells )
{
    num_cells_ = num_cells;
    num_free_cells_ = num_cells_;
    mem_beg_ = &mempool_buffer[0];
    next_ = mem_beg_;
}


template<typename T, size_t NumCells>
void MemPool<T, NumCells>::DestroyPool()
{
    mem_beg_ = nullptr;
}


template<typename T, size_t NumCells>
T* MemPool<T, NumCells>::Allocate()
{
    if ( num_init_ < num_cells_ )
    {
        uint32_t* p = reinterpret_cast<uint32_t*>( AddrFromIndex( num_init_ ) );
        *p = ++num_init_;
    }

    T* res = nullptr;

    if ( num_free_cells_ > 0 )
    {
        res = reinterpret_cast<T*>( next_ );

        if ( --num_free_cells_ > 0 )
        {
            next_ = AddrFromIndex( *reinterpret_cast<uint32_t*>( next_ ) );
        }
        else
        {
            next_ = nullptr;
        }
    }

    return res;
}


template<typename T, size_t NumCells>
void MemPool<T, NumCells>::Deallocate( void* p )
{
    *static_cast<uint32_t*>( p ) = next_ == nullptr ? num_cells_ : IndexFromAddr( next_ );
    next_ = static_cast<uint8_t*>( p );
    ++num_free_cells_;
}


template<typename T, size_t NumCells>
uint8_t* MemPool<T,NumCells>::AddrFromIndex( uint32_t i ) const
{
    return mem_beg_ + ( i * cell_size_ );
}


template<typename T, size_t NumCells>
uint32_t MemPool<T, NumCells>::IndexFromAddr( const uint8_t* p ) const
{
    return static_cast<uint32_t>( p - mem_beg_ ) / cell_size_;
}
