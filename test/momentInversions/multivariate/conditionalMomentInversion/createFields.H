Info<< "Reading quadratureProperties\n" << endl;

dictionary quadratureProperties(IFstream("quadratureProperties")());

labelListList nodeIndexes = quadratureProperties.lookup("nodes");
labelListList momentOrders = quadratureProperties.lookup("moments");

labelList velocityIndexes =
    quadratureProperties.lookupOrDefault
    (
        "velocityIndexes",
        labelList(label(1), -1)
    );

label nNodes = nodeIndexes.size();
label nMoments = momentOrders.size();
label nDims = momentOrders[0].size();
