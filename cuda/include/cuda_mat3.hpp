#ifndef OPENCV_CORE_CUDA_MAT3_HPP
#define OPENCV_CORE_CUDA_MAT3_HPP

#ifndef __cplusplus
#  error cuda.hpp header must be compiled as C++
#endif

#include "opencv2/core.hpp"
#include "cuda_types3.hpp"


namespace cv {
	namespace cuda {

		class CV_EXPORTS GpuMat3 {

		public:

			// GpuMat3(Mat &mat);
			
			GpuMat3();

			size_t elemSize() const;

			void release();

			void create(int x, int y, int z, int type);

			void upload(Mat &mat);

			void download(Mat &mat) const;

			template <class T>
			operator PtrStepSz3<T>() const;

			template <class T>
			operator PtrStep3<T>() const;

			int type() const;

			bool empty() const;

			/*! includes several bit-fields:
			- the magic signature
			- continuity flag
			- depth
			- number of channels
			*/
			int flags;

			//! the number of rows and columns
			int x, y, z;

			//! a distance between successive rows in bytes; includes the gap if any
			size_t stepy;

			//! a distance between successive planes in bytes
			size_t stepz;

			//! pointer to the data
			uchar* data;

		};

	}
}

#include "cuda_mat3.inl.hpp"

#endif /* OPENCV_CORE_CUDA_MAT3_HPP */
