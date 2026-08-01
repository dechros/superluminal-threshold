#pragma once

#include "core/Matrix4.h"
#include "core/Section.h"

namespace slm
{

    /// Section testing direction dependent candidates that would replace the
    /// fixed matrix D.
    class DirectionDependentD : public Section
    {
    public:
        /// Which candidate block form to build.
        enum class Form
        {
            Zaopo,         ///< [[0, -n^T], [-n, I - P]]
            PlusIdentity,  ///< [[0, n^T], [n, I - P]]
            MinusIdentity  ///< [[0, n^T], [n, P - I]]
        };

        /// Builds a candidate for the direction given in spherical angles.
        /// \param theta Polar angle of n.
        /// \param phi Azimuthal angle of n.
        static Matrix4 candidate(Form form, double theta, double phi);

        /// Householder type candidate, [[0, n^T], [n, I - 2P]].
        static Matrix4 householder(double theta, double phi);

        std::string number() const override { return "18"; }
        std::string title() const override
        {
            return "Direction dependent candidates for D";
        }
        void run(Report &report) const override;
    };

}
