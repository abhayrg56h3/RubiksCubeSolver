import React, { createContext, useContext, useState } from 'react';

// Create the context
export const CubeContext = createContext();




export default function Context({ children }) {
    const [solutionMoves, setSolutionMoves] = useState(null);
     const [face0Color, setFace0Color] = useState([['N', 'N', 'N'], ['N', 'N', 'N'], ['N', 'N', 'N']]);
      const [face1Color, setFace1Color] = useState([['N', 'N', 'N'], ['N', 'N', 'N'], ['N', 'N', 'N']]);
      const [face2Color, setFace2Color] = useState([['N', 'N', 'N'], ['N', 'N', 'N'], ['N', 'N', 'N']]);
      const [face3Color, setFace3Color] = useState([['N', 'N', 'N'], ['N', 'N', 'N'], ['N', 'N', 'N']]);
      const [face4Color, setFace4Color] = useState([['N', 'N', 'N'], ['N', 'N', 'N'], ['N', 'N', 'N']]);
      const [face5Color, setFace5Color] = useState([['N', 'N', 'N'], ['N', 'N', 'N'], ['N', 'N', 'N']]);

    return (
        <div><CubeContext.Provider value={{ solutionMoves, setSolutionMoves, face0Color, setFace0Color, face1Color, setFace1Color, face2Color, setFace2Color, face3Color, setFace3Color, face4Color, setFace4Color, face5Color, setFace5Color  }}>
            {children}
        </CubeContext.Provider>
        </div>

    );
}


