import javafx.util.Pair;
import java.util.ArrayList;

public class MinHeap <T extends Comparable <T>> {

	private ArrayList <T> heap;

	public MinHeap() {
		heap = new ArrayList <T>( 32 );
		heap.add( null );
	}

	private MinHeap( T[] array ) {
		heap = new ArrayList <T>( 2 );
		heap.add( null );

		if ( array == null || array.length < 1 ) {
			return;
		}

		heap.ensureCapacity( array.length + 2 );
		for ( int i = 0; i < array.length; ++i ) {
			heap.add( array[ i ] );
		}

		for ( int i = ( heap.size() ) / 2; i >= 1; --i ) {
			bubbleDown( i );
		}
	}

	public void insert( T element ) {
		heap.add( element );
		bubbleUp( heap.size() - 1 );
	}

	public boolean isEmpty() {
		return ( heap.size() <= 1 );
	}

	public T getMin() throws EmptyHeapException {
		if ( heap.size() <= 1 ) {
			throw new EmptyHeapException( "getMin" );
		}

		return heap.get( 1 );
	}

	public void extractMin() throws EmptyHeapException {
		if ( heap.size() <= 1 ) {
			throw new EmptyHeapException( "extractMin" );
		}

		heap.set( 1, heap.get( heap.size() - 1 ) );
		heap.remove( heap.size() - 1 );
		bubbleDown( 1 );
	}

	public static <E extends Comparable <E>> MinHeap <E> makeHeap( E[] array ) {
		return new MinHeap <E>( array );
	}

	private void bubbleUp( int n ) {
		if ( n > 1 ) {
			T parent = heap.get( n >> 1 );

			if ( parent.compareTo( heap.get( n ) ) == 1 ) {
				heap.set( n >> 1, heap.get( n ) );
				heap.set( n, parent );

				bubbleUp( n >> 1 );
			}
		}
	}

	private void bubbleDown( int n ) {
		if ( ( ( n << 1 ) + 1 ) < heap.size() || ( n << 1 ) < heap.size() ) {
			Pair <Integer, T> son = getSonWithLowerKey( n );

			if ( son.getValue().compareTo( heap.get( n ) ) == -1 ) {
				heap.set( son.getKey(), heap.get( n ) );
				heap.set( n, son.getValue() );

				bubbleDown( son.getKey() );
			}
		}
	}

	private Pair <Integer, T> getSonWithLowerKey( int n ) {
		int leftSonIndex  = n << 1;
		int rightSonIndex = leftSonIndex + 1;

		if ( rightSonIndex >= heap.size() ) {
			return new Pair <Integer, T>( leftSonIndex, heap.get( leftSonIndex ) );
		}

		T leftSon  = heap.get( leftSonIndex );
		T rightSon = heap.get( rightSonIndex );

		if ( leftSon.compareTo( rightSon ) < 0 ) {
			return new Pair <Integer, T>( leftSonIndex, leftSon );
		}

		return new Pair <Integer, T>( rightSonIndex, rightSon );
	}

}

class EmptyHeapException extends Exception {

	public EmptyHeapException( String action ) {
		super( "Heap is empty. Cannot perform action '".concat( action ).concat( "'." ) );
	}

}
