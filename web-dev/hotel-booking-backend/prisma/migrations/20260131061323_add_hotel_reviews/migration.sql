/*
  Warnings:

  - Added the required column `rating` to the `Hotel` table without a default value. This is not possible if the table is not empty.
  - Added the required column `total_reviews` to the `Hotel` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "Hotel" ADD COLUMN     "rating" DOUBLE PRECISION NOT NULL,
ADD COLUMN     "total_reviews" INTEGER NOT NULL;
